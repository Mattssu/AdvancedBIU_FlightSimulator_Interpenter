//
// Created by liran on 12/18/18.
//

#ifndef FIRSTMILESTONE_MINUS_H
#define FIRSTMILESTONE_MINUS_H


#include "BinaryExpression.h"

/**
 * Class for minus functionality
 */
class Minus : public BinaryExpression {
public :
    double calculate() {
        return left->calculate() - right->calculate();
    }

    /**
     *
     * @param left Expression
     * @param right Expression
     */
    Minus(Expression *left, Expression *right) : BinaryExpression(left, right) {}

    ~Minus() {
        delete (left);
        delete (right);
    }
};


#endif //FIRSTMILESTONE_MINUS_H