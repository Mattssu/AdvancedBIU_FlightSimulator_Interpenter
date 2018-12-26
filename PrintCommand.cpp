//
// Created by lab on 12/23/18.
//

#include "PrintCommand.h"

PrintCommand::PrintCommand(vector<string> params) {
    this->param = params;
}

void PrintCommand::doCommand() {
    if (param.size() != 1) {
        throw invalid_argument("WRONG PRINT SYNTAX");
    }
    if (param[0].at(0) == '\"' && param[0].at(param[0].size() - 1) == '\"') {
        param[0] = param[0].substr(1, param[0].size() - 2);
        cout << param[0] << endl;
    } else {
        stringToExpression *se = new stringToExpression(param[0]);
        cout << se->ShunYardAlgo() << endl;
        delete (se);
    }

}