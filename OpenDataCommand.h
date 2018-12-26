//
// Created by lab on 12/21/18.
//

#ifndef EX3_OPENDATASERVERCOMMAND_H
#define EX3_OPENDATASERVERCOMMAND_H

#include <vector>
#include <string>
#include "Command.h"

#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include "Command.h"
#include "dataHandler.h"

using namespace std;

/**
* Sets the command OpenDataServer which
* creates a thread that runs the server
*/
class OpenDataCommand : public Command {
private:
    vector<string> param;
public:
    OpenDataCommand(vector<string> params);

    void doCommand();

    ~OpenDataCommand() {}
};


#endif //EX3_OPENDATASERVERCOMMAND_H
