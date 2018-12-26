//
// Created by lab on 12/22/18.
//

#ifndef EX3_COMMANDSFACTORY_H
#define EX3_COMMANDSFACTORY_H

#include <vector>
#include "Command.h"
#include "Expression.h"
#include "CommandExpression.h"
#include "string"

using namespace std;

/**
 * Interface for making a Factory of diff Commands
 * must be implemented by each Command so that it will
 * be used by condition commands.
 */
class CommandsFactory {
public:
    /**
    * returns a new command with parameters
    */
    virtual Expression *runCommand(const vector<Expression *> &commands,
                                   const vector<string> &param) = 0;

    //virtual ~CommandsFactory() = 0;
};

#endif //EX3_COMMANDSFACTORY_H
