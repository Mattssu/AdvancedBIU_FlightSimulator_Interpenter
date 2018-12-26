//
// Created by lab on 12/23/18.
//

#ifndef EX3_IFCONCOMMAND_H
#define EX3_IFCONCOMMAND_H


#include "ConditionCommand.h"

/**
* Sets the command IF which
* has a condition and a set of commands
*/
class IfConCommand : public ConditionCommand {
    vector<Expression *> commands;
public:
    IfConCommand(vector<string> vec, vector<Expression *> commandsList) : ConditionCommand(vec) {
        commands = commandsList;
    }

    virtual void doCommand();

    ~IfConCommand();
};


#endif //EX3_IFCONCOMMAND_H
