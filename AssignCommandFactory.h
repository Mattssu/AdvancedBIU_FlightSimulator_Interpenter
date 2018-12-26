//
// Created by lab on 12/22/18.
//

#ifndef EX3_ASSIGNCOMMANDFACTORY_H
#define EX3_ASSIGNCOMMANDFACTORY_H

#include "CommandsFactory.h"
#include "AssignCommand.h"

/**
 * Creates objects of type Assign Command
 */
class AssignCommandFactory : public CommandsFactory {
public:
    /**
    * returns a new command with parameters
    */
    Expression *runCommand(const vector<Expression *> &commands, const vector<string> &param) {
        return new CommandExpression(new AssignCommand(param));
    }

};


#endif //EX3_ASSIGNCOMMANDFACTORY_H
