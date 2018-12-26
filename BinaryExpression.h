//
// Created by liran on 12/17/18.
//

#ifndef FIRSTMILESTONE_BINARYEXPRESSION_H
#define FIRSTMILESTONE_BINARYEXPRESSION_H

#include "Expression.h"

/**
 * Base class for binary expressions
 */
class BinaryExpression : public Expression {

public :
    Expression *left;
    Expression *right;

    BinaryExpression(Expression *left, Expression *right) : left(left), right(right) {}

//    Expression* getLeft() {
//        return left;
//    }
//    Expression* getRight() {
//        return right;
//    }
};

#endif //FIRSTMILESTONE_BINARYEXPRESSION_H
