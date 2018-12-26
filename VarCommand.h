//
// Created by lab on 12/21/18.
//

#ifndef EX3_VARCOMMAND_H
#define EX3_VARCOMMAND_H

#include <vector>
#include <string>
#include "Command.h"

using namespace std;

/**
* Sets the command Var which
* makes a new Var
*/
class VarCommand : public Command {
private:
    vector<string> param;
public:
    VarCommand(vector<string> params);

    void doCommand();

    ~VarCommand() {}
};


#endif //EX3_VARCOMMAND_H
