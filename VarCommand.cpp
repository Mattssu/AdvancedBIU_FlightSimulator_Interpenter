//
// Created by lab on 12/21/18.
//

#include "VarCommand.h"
#include "outputHandler.h"
#include "dataHandler.h"

VarCommand::VarCommand(vector<string> params) {
    param = params;
}

void VarCommand::doCommand() {
    if (param.size() == 3 || param.size() == 4) {
        if (param.size() == 3) {
            if (param[1] != "=") {
                throw "WRONG VAR DECLARATION";
            }
            //var y = 3
            stringToExpression *e1 = new stringToExpression(param[2]);
            dataHandler::addNameToValue(param[0], e1->ShunYardAlgo());
            delete (e1);
        } else {
            if (param[1] != "=" || param[2] != "bind") {
                throw "WRONG VAR DECLARATION";
            }
            //var y = bind "path"
            if (param[3].at(0) == '\"' && param[3].at(param[3].size() - 1) == '\"') {
                string t = param[3];
                //fix
                t = t.substr(1, t.size() - 2);
                if (dataHandler::getPathToValue(t) == nullptr) {
                    dataHandler::addNonXmlToPath(param[0], t);
                } else {
                    outputHandler::bind(param[0], t);
                }
            } else {
                //var y = bind x
                dataHandler::addNameToPath(param[0], *dataHandler::getNameToPath(param[3]));
                /*
                static map<string, string> p;
                p = dataHandler::getTestPath();
                p = dataHandler::getTestPath();
                 */
            }
        }
    } else {
        throw "WRONG VAR DECLARATION";
    }
}