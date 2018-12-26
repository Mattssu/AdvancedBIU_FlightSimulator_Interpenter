//
// Created by lab on 12/23/18.
//

#ifndef EX3_MUL_H
#define EX3_MUL_H


#include "BinaryExpression.h"

/**
 * Class for Multiply functionality
 */
class Mul : public BinaryExpression {
public :
    double calculate() {
        return left->calculate() * right->calculate();
    }

    /**
     *
     * @param left Expression
     * @param right Expression
     */
    Mul(Expression *left, Expression *right) : BinaryExpression(left, right) {}

    ~Mul() {
        delete (left);
        delete (right);
    }
};


#endif //EX3_MUL_H
