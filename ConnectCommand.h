//
// Created by lab on 12/21/18.
//

#ifndef EX3_CONNECTCOMMAND_H
#define EX3_CONNECTCOMMAND_H

#include <vector>
#include <string>
#include "Command.h"

using namespace std;

/**
* Sets the command Connect which
* connects the client to the simulator
*/
class ConnectCommand : public Command {
private:
    vector<string> param;
public:
    ConnectCommand(vector<string> params);

    void doCommand();

    void connectToSim(vector<string> list);

    ~ConnectCommand() {};
};


#endif //EX3_CONNECTCOMMAND_H
