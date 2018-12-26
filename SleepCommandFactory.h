//
// Created by lab on 12/26/18.
//

#ifndef EX3_SLEEPCOMMANDFACTORY_H
#define EX3_SLEEPCOMMANDFACTORY_H


#include "CommandsFactory.h"
#include "SleepCommand.h"

/**
 * Creates objects of type Sleep Command
 */
class SleepCommandFactory : public CommandsFactory {
public:
    /**
    * returns a new command with parameters
    */
    virtual Expression *runCommand(const vector<Expression *> &commands, const vector<string> &params) {
        return new CommandExpression(new SleepCommand(params));
    }
};


#endif //EX3_SLEEPCOMMANDFACTORY_H
