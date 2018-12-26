//
// Created by lab on 12/23/18.
//

#ifndef EX3_PRINTCOMMAND_H
#define EX3_PRINTCOMMAND_H

#include <iostream>
#include "Command.h"

/**
* Sets the command Print which
* prints output on screen
*/
class PrintCommand : public Command {
    vector<string> param;

public:
    PrintCommand(vector<string> params);

    virtual void doCommand();

    ~PrintCommand() {}
};


#endif //EX3_PRINTCOMMAND_H
