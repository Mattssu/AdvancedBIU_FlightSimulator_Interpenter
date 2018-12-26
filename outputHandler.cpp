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
#include "ConnectCommand.h"
#include "outputHandler.h"
#include "dataHandler.h"
//
#include "OpenDataCommand.h"

//in order to use static private
int outputHandler::sockFd = -1;
int outputHandler::DataServerSocket = -1;
bool outputHandler::isServerOpen = false;

/**
 * Sets client info
 */
void outputHandler::setSocketInfo(int sock) {
    sockFd = sock;
    //cout << to_string(sockFd);
}

/**
 * send set requests to the simulator
 */
void outputHandler::sendToSim(string str, double val) {
    string s = *dataHandler::getNameToPath(str);
    s = s.substr(1, s.size() - 1);
    string command = "set " + s + " " + std::to_string(val) + "\r\n";
    //cout << sockFd << endl;
    int n = write(sockFd, command.c_str(), command.length());
    //if error
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}

/**
 * send set requests to the simulator
 */
void outputHandler::sendToSimNonXml(string str, double val) {
    string s = *dataHandler::getNameToNonXmlPath(str);
    s = s.substr(1, s.size() - 1);
    string command = "set " + s + " " + std::to_string(val) + "\r\n";
    //cout << sockFd << endl;
    int n = write(sockFd, command.c_str(), command.length());
    //if error
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}

/**
 * basically uses addNameToPath
 */
void outputHandler::bind(string name, string path) {
    dataHandler::addNameToPath(name, path);
}

/**
 * sets server info
 */
void outputHandler::setServerInfo(int *socket, pthread_t *thread) {
    DataServerSocket = *socket;
    //th = thread;
    isServerOpen = true;
}

/**
 * checks if server IsOpen
 */
bool outputHandler::isOpen() {
    return isServerOpen;
}

/**
 * turns off the server and client
 * and thread
 */
void outputHandler::turnOffConnection() {

    //Close the client socket to the simulator
    if (sockFd > 0) {
        close(sockFd);
    }

    //Close Data Server Socket
    if (DataServerSocket > 0) {
        isServerOpen = false;
        close(DataServerSocket);
    }

}