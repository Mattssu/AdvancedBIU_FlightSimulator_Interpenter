//
// Created by lab on 12/18/18.
//

#ifndef EX3_COMMAND_H
#define EX3_COMMAND_H

#include <string>
#include <vector>
#include "Expression.h"
#include "stringToExpression.h"

using namespace std;

/**
 * Interface of Command
 */
class Command {
public:
    //starts a command
    virtual void doCommand() = 0;

    // a destructor to prevent leaks
    virtual ~Command() {}
};


#endif //EX3_COMMAND_H
