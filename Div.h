//
// Created by liran on 12/18/18.
//

#ifndef FIRSTMILESTONE_DIV_H
#define FIRSTMILESTONE_DIV_H

#include "BinaryExpression.h"

/**
 * Class for divide functionality
 */
class Div : public BinaryExpression {
public :
    double calculate() {
        return left->calculate() / right->calculate();
    }

    /**
     * Divide
     * @param left expression
     * @param right expression
     */
    Div(Expression *left, Expression *right) : BinaryExpression(left, right) {}

    ~Div() {
        delete (left);
        delete (right);
    }
};

#endif //FIRSTMILESTONE_DIV_H
