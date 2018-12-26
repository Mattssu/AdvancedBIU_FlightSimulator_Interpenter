//
// Created by lab on 12/21/18.
//

#include "AssignCommand.h"
#include "dataHandler.h"
#include "outputHandler.h"

/**
 * Constructor
 */
AssignCommand::AssignCommand(vector<string> params) {
    param = params;
}

/**
 * Sets the command Assign which
 * sets a value to an existing Var
 */
void AssignCommand::doCommand() {
    if (param.size() != 3) {
        throw "INVALID VALUE UPDATE";
    }
    //if is bind'ed
    stringToExpression *e = new stringToExpression(param[2]);
    if (dataHandler::getNameToPath(param[0]) != nullptr) {
        outputHandler::sendToSim(param[0], e->ShunYardAlgo());
    } else if (dataHandler::getNameToNonXmlPath(param[0]) != nullptr) {
        outputHandler::sendToSimNonXml(param[0], e->ShunYardAlgo());
    } else {
        dataHandler::addNameToValue(param[0], e->ShunYardAlgo());
        static map<string, double> p;
        p = dataHandler::getValueMap();
        p = dataHandler::getValueMap();
    }
    delete (e);
}