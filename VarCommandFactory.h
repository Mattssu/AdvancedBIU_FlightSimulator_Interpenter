//
// Created by lab on 12/22/18.
//

#ifndef EX3_VARCOMMANDFACTORY_H
#define EX3_VARCOMMANDFACTORY_H

#include "CommandsFactory.h"
#include "VarCommand.h"

/**
 * Creates objects of type Var Command
 */
class VarCommandFactory : public CommandsFactory {
public:
    /**
    * returns a new command with parameters
    */
    Expression *runCommand(const vector<Expression *> &commands, const vector<string> &param) {
        return new CommandExpression(new VarCommand(param));
    }

};


#endif //EX3_VARCOMMANDFACTORY_H
