//
// Created by lab on 12/23/18.
//

#ifndef EX3_CONDITIONCOMMAND_H
#define EX3_CONDITIONCOMMAND_H

#include "Command.h"

/**
 * An base class that implements Conditions
 */
class ConditionCommand : public Command {
protected:
    vector<string> param;
public:
    /**
     * A constructor
     */
    ConditionCommand(vector<string> list);

    /**
     * Checks if condition valid
     */
    bool isValid();

    ~ConditionCommand() {
    }
};


#endif //EX3_CONDITIONCOMMAND_H
