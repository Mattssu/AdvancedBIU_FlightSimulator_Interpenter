//
// Created by lab on 12/22/18.
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

/**
 * runs the server on a thread and receives
 * data from the simulator
 */
void *openServer(void *params) {
    //get param
    int *arr = (int *) params;
    int newsockfd = *arr;
    int speed = *(arr + 1);
    //create buffer and n (for debug)
    char buffer[400];
    int n = 0;
    bzero(buffer, 400);
    //to keep track of info received from simulator
    string line = "";
    string prevline = "";
    vector<double> vec;
    //keeps on running unless received boolean to stop
    while (outputHandler::isOpen()) {
        //keep track of position
        int pos = 0;
        /* If connection is established then start communicating */
        n = read(newsockfd, buffer, 400);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        //Loop to receive 23 values.
        line += std::string(buffer);
        for (int i = 0; i < 22; i++) {
            pos = line.find_first_of(",");
            vec.push_back(stod(line.substr(0, pos)));
            line.erase(0, pos + 1);
        }
        //the 23'rd value and we delete up to \n
        vec.push_back(stod(line.substr(0, line.find_first_of("\n"))));
        line.erase(0, line.find_first_of("\n") + 1);
        //updates the values in Map
        dataHandler::addPathToValue(vec);
        vec.clear();
        //reading speed
        sleep(1.0 / speed);
    }
}

/**
 * receives the first data from the simulator
 * to know that we can open the server and keep going
 */
void runOnce(int newsockfd) {
    //create buffer and n (for debug)
    char buffer[400];
    int n = 0;
    bzero(buffer, 400);
    //to keep track of info received from simulator
    string line = "";
    string prevline = "";
    vector<double> vec;
    //keeps on running unless received boolean to stop

    //keep track of position
    int pos = 0;
    /* If connection is established then start communicating */
    n = read(newsockfd, buffer, 400);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    //Loop to receive 23 values.
    line += std::string(buffer);
    for (int i = 0; i < 22; i++) {
        pos = line.find_first_of(",");
        vec.push_back(stod(line.substr(0, pos)));
        line.erase(0, pos + 1);
    }
    //the 23'rd value and we delete up to \n
    vec.push_back(stod(line.substr(0, line.find_first_of("\n"))));
    line.erase(0, line.find_first_of("\n") + 1);
    //updates the values in Map
    dataHandler::addPathToValue(vec);
    vec.clear();
}

/**
 * creates a socket and passes param to the thread
 * it opens.
 */
void OpenDataCommand::doCommand() {
    //init map values
    dataHandler::initPathToValue();
    if (param.size() != 2) {
        throw "INVALID NUM OF PARAMETERS";
    }
    stringToExpression *e1 = new stringToExpression(param[0]);
    stringToExpression *e2 = new stringToExpression(param[1]);
    //convert to int
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
    /* Now start listening for the clients*/
    listen(sockfd, 1);
    clilen = sizeof(cli_addr);
    /* Accept actual connection from the client */
    newsockfd = ::accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    //RUN ONCE
    runOnce(newsockfd);
    //create thread
    pthread_t server;
    //allocate arr
    int speed = p2;
    int *arr = new int[2];
    arr[0] = newsockfd;
    arr[1] = speed;
    //release memory
    delete (e1);
    delete (e2);
    //Run the thread for the updating
    pthread_create(&server, nullptr, &openServer, (void *) arr);
    //set info for later use
    outputHandler::setServerInfo(&newsockfd, &server);
}