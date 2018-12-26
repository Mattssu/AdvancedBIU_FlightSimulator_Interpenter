//
// Created by ofir8 on 12/20/18.
//


#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <pthread.h>
#include <fstream>
//
#include "OpenDataCommand.h"
#include "outputHandler.h"

OpenDataCommand::OpenDataCommand(vector<string> params) {
    param = params;
}

void *openServer(void *params) {
    int *arr = (int *) params;
    int newsockfd = *arr;
    int h = *(arr + 1);
    //delete[] &params;
    //
    //delete (arr);
    char buffer[400];
    int n = 0;
    //cout << to_string(h) + " " + to_string(newsockfd) << endl;
    bzero(buffer, 400);
    string line = "";
    string prevline = "";
    vector<double> vec;
    while (outputHandler::isOpen()) {
        //pthread_mutex_lock(&lock);
        int pos, prev = 0;
        /* If connection is established then start communicating */
        n = read(newsockfd, buffer, 400);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        line += std::string(buffer);
        if ("exit" == std::string(buffer)) {
            cout << "simulator disconncted" << endl;
            break;
        }
        //line = line.erase(line.find_first_of("\n"),1);
        for (int i = 0; i < 22; i++) {
            pos = line.find_first_of(",");
            vec.push_back(stod(line.substr(0, pos)));
            line.erase(0, pos + 1);
        }
        vec.push_back(stod(line.substr(0, line.find_first_of("\n"))));
        line.erase(0, line.find_first_of("\n") + 1);

        dataHandler::addPathToValue(vec);
        vec.clear();
        sleep(1.0 / h);
    }
    delete (arr);
}

void OpenDataCommand::doCommand() {
    dataHandler::initPathToValue();
    if (param.size() != 2) {
        throw "INVALID NUM OF PARAMETERS";
    }
    stringToExpression *e1 = new stringToExpression(param[0]);
    stringToExpression *e2 = new stringToExpression(param[1]);
    //int arr[2] = {(int) e1->ShunYardAlgo(), (int) e2->ShunYardAlgo()};
    int p1 = e1->ShunYardAlgo();
    int p2 = e2->ShunYardAlgo();
    //Create the server
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    //int n;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    serv_addr.sin_port = htons(p1);
    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */
    listen(sockfd, 1);
    clilen = sizeof(cli_addr);
    /* Accept actual connection from the client */
    cout << "waiting" << endl;
    newsockfd = ::accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
    cout << "connected" << endl;
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    pthread_t server;
    int h = p2;
    int *arr = new int(2);
    arr[0] = newsockfd;
    arr[1] = h;
    delete (e1);
    delete (e2);
    //Run the thread for the updating
    pthread_create(&server, nullptr, &openServer, (void *) arr);
    outputHandler::setServerInfo(&newsockfd, &server);
}