//
// Created by lab on 12/23/18.
//

#ifndef EX3_LOOPCOMMANDS_H
#define EX3_LOOPCOMMANDS_H


#include "ConditionCommand.h"

/**
* Sets the command While which
* gets a condition and a group of commands
*/
class WhileCommand : public ConditionCommand {
    vector<Expression *> commands;
public:
    WhileCommand(vector<string> vec, vector<Expression *> commandsList) : ConditionCommand(vec) {
        commands = commandsList;
    }

    virtual void doCommand();

    ~WhileCommand();
};


#endif //EX3_LOOPCOMMANDS_H
