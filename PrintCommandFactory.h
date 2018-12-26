//
// Created by lab on 12/23/18.
//

#ifndef EX3_PRINTCOMMANDFACTORY_H
#define EX3_PRINTCOMMANDFACTORY_H


#include "CommandsFactory.h"
#include "PrintCommand.h"

/**
 * Creates objects of type Print Command
 */
class PrintCommandFactory : public CommandsFactory {
public:
    /**
    * returns a new command with parameters
    */
    virtual Expression *runCommand(const vector<Expression *> &commands, const vector<string> &params) {
        return new CommandExpression(new PrintCommand(params));
    }
};


#endif //EX3_PRINTCOMMANDFACTORY_H
