//
// Created by lab on 12/22/18.
//

#ifndef EX3_OPENDATACOMMANDFACTORY_H
#define EX3_OPENDATACOMMANDFACTORY_H

#include "CommandsFactory.h"
#include "OpenDataCommand.h"

/**
 * Creates objects of type OpenDataServer Command
 */
class OpenDataCommandFactory : public CommandsFactory {
    /**
    * returns a new command with parameters
    */
    Expression *runCommand(const vector<Expression *> &commands, const vector<string> &param) {
        return new CommandExpression(new OpenDataCommand(param));
    }
};


#endif //EX3_OPENDATACOMMANDFACTORY_H
