//
// Created by lab on 12/26/18.
//

#ifndef EX3_SLEEPCOMMAND_H
#define EX3_SLEEPCOMMAND_H

#include <unistd.h>
#include "Command.h"

/**
* Sets the command Sleep which
* makes the thread sleep
*/
class SleepCommand : public Command {
    vector<string> param;
public:
    SleepCommand(vector<string> params) {
        param = params;
    }

    void doCommand() {
        stringToExpression *e = new stringToExpression(param[0]);
        sleep((unsigned int) (e->ShunYardAlgo() / 1000));
        delete (e);
    };

    ~SleepCommand() {}
};

#endif //EX3_SLEEPCOMMAND_H
