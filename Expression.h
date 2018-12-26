//
// Created by liran on 12/17/18.
//

#ifndef FIRSTMILESTONE_EXPRESSION_H
#define FIRSTMILESTONE_EXPRESSION_H

/**
 * Base class for expressions
 */
class Expression {
public :
    /**
     * @return return the wanted calculate.
     */
    virtual double calculate() = 0;

    virtual ~Expression() {}
};


#endif //FIRSTMILESTONE_EXPRESSION_H
