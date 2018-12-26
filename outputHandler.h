//
// Created by lab on 12/21/18.
//

#ifndef EX3_OUTPUTHANDLER_H
#define EX3_OUTPUTHANDLER_H

/**
 * sort of static class that handles all the output and connection
 * with simulator and dataServer
 */
class outputHandler {
public:
    static int serverSock;
    static bool isServerOpen;
    static int sockFd;
    static pthread_t *server;

    /**
    * sets client info
    */
    static void setSocketInfo(int sock);

    /**
     * sets server info
     */
    static void setServerInfo(int *socket, pthread_t *thread);

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
    * returns the thread
    */
    static pthread_t *getThread();

    /**
     * turns off the server and client
     * and thread
     */
    static void turnOffConnection();
};


#endif //EX3_OUTPUTHANDLER_H
