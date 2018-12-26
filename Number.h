//
// Created by liran on 12/17/18.
//

#ifndef FIRSTMILESTONE_NUMBER_H
#define FIRSTMILESTONE_NUMBER_H

#include "Expression.h"

/**
 * Class that serves as a number
 */
class Number : public Expression {
    double value;
public :
    Number(double value) : value(value) {}

    double calculate() {
        return value;
    }

    ~Number() {}

};

#endif //FIRSTMILESTONE_NUMBER_H