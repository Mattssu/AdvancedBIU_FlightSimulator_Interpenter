//
// Created by lab on 12/23/18.
//

#ifndef EX3_IFCOMMAND_H
#define EX3_IFCOMMAND_H

#include "CommandsFactory.h"
#include "IfConCommand.h"

/**
 * Creates objects of type If Command
 */
class IfCommandFactory : public CommandsFactory {
public:
    /**
    * returns a new command with parameters
    */
    Expression *runCommand(const vector<Expression *> &commands, const vector<string> &param) {
        return new CommandExpression(new IfConCommand(param, commands));
    }

};


#endif //EX3_IFCOMMAND_H
