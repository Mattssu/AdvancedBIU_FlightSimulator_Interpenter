//
// Created by liran on 12/17/18.
//

#ifndef FIRSTMILESTONE_PLUS_H
#define FIRSTMILESTONE_PLUS_H

#include "BinaryExpression.h"

/**
 * Class for plus functionality
 */
class Plus : public BinaryExpression {
public :
    double calculate() {
        return left->calculate() + right->calculate();
    }

    /**
     *
     * @param left Expression
     * @param right Expression
     */
    Plus(Expression *left, Expression *right) : BinaryExpression(left, right) {}

    ~Plus() {
        delete (left);
        delete (right);
    }
};


#endif //FIRSTMILESTONE_PLUS_H
