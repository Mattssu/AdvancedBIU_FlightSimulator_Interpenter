//
// Created by lab on 12/22/18.
//

#ifndef EX3_CONNECTCOMMANDFACTORY_H
#define EX3_CONNECTCOMMANDFACTORY_H

#include "CommandsFactory.h"
#include "ConnectCommand.h"
/**
 * Creates objects of type ConnectCommand Command
 */
class ConnectCommandFactory : public CommandsFactory {
public:
    /**
    * returns a new command with parameters
    */
    Expression *runCommand(const vector<Expression *> &commands, const vector<string> &param) {
        return new CommandExpression(new ConnectCommand(param));
    }
};


#endif //EX3_CONNECTCOMMANDFACTORY_H
