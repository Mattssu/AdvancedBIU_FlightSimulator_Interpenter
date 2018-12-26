//
// Created by lab on 12/21/18.
//
#include <string>
#include "dataParser.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


/**
 * if sees comma it understands there are 2 params
 */
vector<string> commaHandler(string param) {
    vector<string> lineArgs;
    //for multiple negative param
    stringstream stringStream(param);
    while (std::getline(stringStream, param)) {
        string temp;
        std::size_t prev = 0, pos;
        //finds location of symbol
        while ((pos = param.find_first_of(",", prev)) != string::npos) {
            if (pos > prev)
                lineArgs.push_back(param.substr(prev, pos - prev));
            prev = pos + 1;
        }
        if (prev < param.length())
            lineArgs.push_back(param.substr(prev, string::npos));
    }
    return lineArgs;
}

/**
 * swaps Var to Value
 */
string dataParser::fill(string str) {
    map<string, double> map = dataHandler::getValueMap();
    string name;
    string value;
    for (auto const &x : map) {
        name = x.first;
        value = to_string(x.second);
        if (str == name) {
            return value;
        }
    }
    return str;
}

/**
 * takes a line and splits by delimiter into vector of strings
 */
vector<string> dataParser::lexer(string line) {
    vector<string> lineArgs;
    //lineArgs = split(line);
    //
    //line = clearSpaces(line);
    stringstream stringStream(line);
    while (std::getline(stringStream, line)) {
        string temp;
        std::size_t prev = 0, pos;
        //finds location of symbol
        while ((pos = line.find_first_of(" ()+-*/=", prev)) != string::npos) {
            if (pos > prev)
                lineArgs.push_back(line.substr(prev, pos - prev));
            prev = pos + 1;
            //suppose to push the symbol in
            char tester = line.at(pos);
            if (tester != ' ') {
                temp.push_back(tester);
                lineArgs.push_back(temp);
                temp = "";
            }
        }
        if (prev < line.length())
            lineArgs.push_back(line.substr(prev, string::npos));
    }
    //
    return lineArgs;
    //readFile(*fName);
}

/**
 * checks if an operator
 */
bool isOperator(string op) {
    if (op == "+" || op == "-" || op == "*" || op == "/") {
        return true;
    } else {
        return false;
    }
}

/**
 * checks if paranthesses
 */
bool isParanthesses(string a, string b) {
    if ((a == ")" && b == "(") || (a != "(" && b == "(")
        || (a == ")" && b != ")") || ((a != "(" && a != ")") && (b != "(" && b != ")"))) {
        return false;
    } else if (a == "(" && b == ")") {
        throw "BAD SYNTAX";
    } else {
        return true;
    }
}

/**
 * checks if a command
 */
bool isCommand(string op) {
    if (op == "openDataServer" || op == "var"
        || op == "connect" || op == "while" || op == "if") {
        return true;
    } else {
        return false;
    }
}
/**
 * checks if its a param
 */
/**
 * checks if both strings are part of smae param
 */
bool isValidParameter(string a, string b) {
    //make strings
    //returns if an operator
    bool a1 = isOperator(a);
    bool b1 = isOperator(b);
    //
    if (a == "=" || b == "=") {
        return false;
    }
    if (isCommand(a)) {
        return false;
    }
    if (!a1 && !b1) {
        if (isParanthesses(a, b)) {
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }
}

/**
 * combines the vector into strings that fit as param
 */
vector<string> dataParser::paramMaker(vector<string> list) {
    vector<string> temp;
    for (int i = 0; i <= list.size() - 1; ++i) {
        string str = list[i];
        //so if last one it just adds him
        if (i != list.size() - 1) {
            while (isValidParameter(list[i], list[i + 1])) {
                str += list[i + 1];
                ++i;
                //to exit if lase was added
                if (i == list.size() - 1) {
                    break;
                }
            }
        }
        //because out of bounds
        temp.push_back(str);
    }
    vector<string> newTemp;
    vector<string> result;
    for (auto it = temp.begin(); it != temp.end(); ++it) {
        newTemp = commaHandler(*it);
        for (auto it = newTemp.begin(); it != newTemp.end(); ++it) {
            result.push_back((*it));
        }
    }
    return result;
}

/**
 * uses the factory map to return an Expression of a command
 */
Expression *dataParser::parser(vector<string> line, map<string, CommandsFactory *> map) {
    line = paramMaker(line);
    if (map.find(line[0]) != map.end()) {
        CommandsFactory *c = map.at(line[0]);
        line.erase(line.begin());
        Expression *command = c->runCommand(vector<Expression *>(), line);
        //
        return command;
    }
    //if existing str = new value
    if (dataHandler::getNameToPath(line[0]) != nullptr ||
        dataHandler::getNameToValue(line[0]) != nullptr ||
        dataHandler::getNameToNonXmlPath(line[0]) != nullptr) {
        if (line[1] == "=") {
            CommandsFactory *c = map.at(line[1]);
            Expression *command = c->runCommand(vector<Expression *>(), line);
            //
            return command;
        }
    }
    //if error
    throw invalid_argument("WRONG SYNTAX OR UNKNOWN COMMAND");
}

/**
 * uses the factory map to return an Expression of a command
 * also checks for inner loops
 */
Expression *dataParser::conditionParser(vector<string> &line, const map<string,
        CommandsFactory *> &map, std::istream &in) {
    vector<Expression *> commands;
    string temp;
    vector<string> conditionParam = line;
    //
    getline(in, temp);
    line = lexer(temp);
    //if theres a loop inside the loop
    do {
        if (line.back() == "{") {
            commands.push_back(conditionParser(line, map, in));
        } else {
            commands.push_back(parser(line, map));
        }
        //
        getline(in, temp);
        line = lexer(temp);
    } while (line.front() != "}");
    //
    conditionParam = paramMaker(conditionParam);
    temp = conditionParam[0];
    conditionParam.erase(conditionParam.begin());
    return map.at(temp)->runCommand(commands, conditionParam);
}