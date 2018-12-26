//
// Created by lab on 12/23/18.
//

#ifndef EX3_WHILEFACTORY_H
#define EX3_WHILEFACTORY_H


#include "CommandsFactory.h"
#include "WhileCommand.h"

/**
 * Creates objects of type While Command
 */
class WhileFactory : public CommandsFactory {
public:
    /**
    * returns a new command with parameters
    */
    virtual Expression *runCommand(const vector<Expression *> &commands, const vector<string> &params) {
        return new CommandExpression(new WhileCommand(params, commands));
    }
};


#endif //EX3_WHILEFACTORY_H
