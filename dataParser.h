//
// Created by lab on 12/21/18.
//

#ifndef EX3_DATAPARSER_H
#define EX3_DATAPARSER_H

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include <regex>
//
#include "Command.h"
#include "dataHandler.h"
#include "CommandExpression.h"
#include "CommandsFactory.h"

using namespace std;

/**
 * this class has all utility tools to work
 * on data such as parser,split etc
 */
class dataParser {
public:
    /**
     * Constructor
     */
    dataParser() = default;

    /**
     * swaps Var to Value
     */
    string fill(string str);

    /**
     * combines the vector into strings that fit as param
     */
    vector<string> paramMaker(vector<string> list);

    /**
     * takes a line and splits by delimiter into vector of strings
     */
    vector<string> lexer(string line);

    /**
     * uses the factory map to return an Expression of a command
     */
    Expression *parser(vector<string> line, map<string, CommandsFactory *> map);

    /**
     * uses the factory map to return an Expression of a command
     * also checks for inner loops
     */
    Expression *conditionParser(vector<string> &line, const map<string, CommandsFactory *> &map, std::istream &in);

};


#endif //EX3_DATAPARSER_H
