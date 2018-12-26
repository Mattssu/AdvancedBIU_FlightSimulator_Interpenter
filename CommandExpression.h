//
// Created by lab on 12/22/18.
//

#ifndef EX3_COMMANDEXPRESSION_H
#define EX3_COMMANDEXPRESSION_H

#include "Expression.h"
#include "Command.h"

/**
 * An Object Adapter for Expression that wraps a Command
 * to make it an Expression type without direct interface implementation
 */
class CommandExpression : public Expression {
private:
    Command *cmd;
public:
    /**
     * A constructor
     */
    CommandExpression(Command *c);

    /**
     * Implemented by Expressions
     */
    double calculate();

    ~CommandExpression() override {
        delete (cmd);
    }
};


#endif //EX3_COMMANDEXPRESSION_H
