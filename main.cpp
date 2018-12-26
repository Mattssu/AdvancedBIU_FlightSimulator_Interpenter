
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include <regex>
//
#include "Command.h"
#include "dataHandler.h"
#include "CommandsFactory.h"
#include "dataParser.h"
#include "outputHandler.h"
//factories
#include "OpenDataCommandFactory.h"
#include "VarCommandFactory.h"
#include "ConnectCommandFactory.h"
#include "AssignCommandFactory.h"
#include "IfCommandFactory.h"
#include "WhileFactory.h"
#include "SleepCommandFactory.h"
#include "PrintCommandFactory.h"

//declarations
using namespace std;

void createCommandList(map<string, CommandsFactory *> &list);

int main(int argc, char *argv[]) {
    /*
    //test
    stringToExpression *e = new stringToExpression("-1 *(-1* -1 ) * -10*-1*-10");
    e = new stringToExpression("1/-2");
    double g = e->ShunYardAlgo();
    */

    //init
    map<string, CommandsFactory *> commandList;
    dataParser *dp = new dataParser();
    createCommandList(commandList);
    string line;
    //
    bool fromFile = false;
    std::ifstream f;
    if (argc == 2) {
        f.open(argv[1]);
        fromFile = true;
    }
    std::istream &in = (argc == 2) ? f : std::cin;

    bool runner = true;
    while (true) {
        getline(in, line);
        //if exit or end of file
        if (!fromFile && line == "exit") {
            break;
        }
        if ((fromFile && in.eof())) {
            if (line.empty() || line == "exit") {
                break;
            }
            runner = false;
        }
        vector<string> list = dp->lexer(line);
        Expression *command;
        if (list.back() == "{") {
            list.pop_back();
            command = dp->conditionParser(list, commandList, in);
        } else {
            command = dp->parser(list, commandList);
        }
        command->calculate();
        delete (command);
        if (!runner) {
            break;
        }
    }
    //pthread_join(*outputHandler::getServerInfo(), nullptr);
    //deletes
    delete (dp);
    auto it = commandList.begin();
    for (; it != commandList.end(); it++) {
        delete (it->second);
    }
    //close thread
    outputHandler::turnOffConnection();
    //delete (commandList);
    return 0;
}

void createCommandList(map<string, CommandsFactory *> &list) {
    list.insert(pair<string, CommandsFactory *>("openDataServer", new OpenDataCommandFactory()));
    list.insert(pair<string, CommandsFactory *>("connect", new ConnectCommandFactory()));
    list.insert(pair<string, CommandsFactory *>("var", new VarCommandFactory()));
    list.insert(pair<string, CommandsFactory *>("=", new AssignCommandFactory()));
    list.insert(pair<string, CommandsFactory *>("if", new IfCommandFactory()));
    list.insert(pair<string, CommandsFactory *>("while", new WhileFactory()));
    list.insert(pair<string, CommandsFactory *>("sleep", new SleepCommandFactory()));
    list.insert(pair<string, CommandsFactory *>("print", new PrintCommandFactory()));
}

