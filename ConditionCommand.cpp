//
// Created by lab on 12/23/18.
//

#include "ConditionCommand.h"

ConditionCommand::ConditionCommand(vector<string> list) {
    param = list;
    //if = = and likewise
    if (param.size() == 4) {
        string a = param[0];
        string b = param[1];
        b += param[2];
        string c = param[3];
        param.clear();
        param.push_back(a);
        param.push_back(b);
        param.push_back(c);
    }
}

bool ConditionCommand::isValid() {
    //init
    stringToExpression *e1 = new stringToExpression(param[0]);
    stringToExpression *e2 = new stringToExpression(param[2]);
    double n1 = e1->ShunYardAlgo();
    double n2 = e2->ShunYardAlgo();
    string op = param[1];
    //
    delete (e1);
    delete (e2);
    //
    if ((op == "==") || (op == "!=") || (op == "<")
        || (op == ">") || (op == "<=") || (op == ">=")) {
        //checks which one
        if ((op == "==") && (n1 == n2)) {
            return true;
        } else if ((op == "!=") && (n1 != n2)) {
            return true;
        } else if ((op == "<") && (n1 < n2)) {
            return true;
        } else if ((op == ">") && (n1 > n2)) {
            return true;
        } else if ((op == "<=") && (n1 <= n2)) {
            return true;
        } else if ((op == ">=") && (n1 >= n2)) {
            return true;
        } else {
            return false;
        }
    } else {
        throw "INVALID OPERATOR";
    }

}