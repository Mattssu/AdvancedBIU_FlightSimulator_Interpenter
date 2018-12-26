//
// Created by lab on 12/21/18.
//

#ifndef EX3_OUTPUTHANDLER_H
#define EX3_OUTPUTHANDLER_H

#include <string>

using namespace std;

/**
 * sort of static class that handles all the output and connection
 * with simulator and dataServer
 */
class outputHandler {
public:
    static int serverSock;
    static bool isServerOpen;
    static int sockFd;

    /**
    * sets client info
    */
    static void setSocketInfo(int sock);

    /**
     * sets server info
     */
    static void setServerInfo(int *socket);

    /**
     * send set requests to the simulator
     */
    static void sendToSim(string str, double val);

    /**
     * send set requests to the simulator
     */
    static void sendToSimNonXml(string str, double val);

    //basically uses addNameToPath
    static void bind(string name, string path);

    /**
    * checks if server IsOpen
    */
    static bool isOpen();

    /**
     * turns off the server and client
     * and thread
     */
    static void turnOffConnection();
};


#endif //EX3_OUTPUTHANDLER_H
