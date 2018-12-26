//
// Created by liran on 12/18/18.
//

#ifndef FIRSTMILESTONE_SHUNYARDALGO_H
#define FIRSTMILESTONE_SHUNYARDALGO_H

#include <stack>
#include <queue>
#include <map>
#include "BinaryExpression.h"
#include "Plus.h"
#include "Minus.h"
#include "Div.h"
#include "Mul.h"
#include "Number.h"
#include <string>

using namespace std;

/**
 * converts string into an Expression
 */
class stringToExpression {
private :
    string token;
    map<char, int> proOfOp;
public :


/**
 *Constructor
 * @param token the string provided.
 */
    stringToExpression(string token) : token(token) {
        initProOfOp();

    }

/**
 * the main action . does the algo .
 */
    double ShunYardAlgo();

/**
 * init the priority of the operators.
 */
    void initProOfOp();
/**
 * makes a pre process for the algo to work
 */
    void preProcessToken();

    ~stringToExpression() = default;
};


#endif //FIRSTMILESTONE_SHUNYARDALGO_H
