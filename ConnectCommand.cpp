//
// Created by lab on 12/21/18.
//
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>
#include <iostream>
#include "ConnectCommand.h"
#include "outputHandler.h"

using namespace std;

ConnectCommand::ConnectCommand(vector<string> params) {
    param = params;
}

void ConnectCommand::doCommand() {
    connectToSim(param);
}

void ConnectCommand::connectToSim(vector<string> list) {
    //init
    stringToExpression *e = new stringToExpression(list[1]);
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    portno = (int) e->ShunYardAlgo();
    //clear memory
    delete (e);

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(list[0].c_str());

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    //connected
    //cout << "Open Socket\n";
    outputHandler::setSocketInfo(sockfd);
}