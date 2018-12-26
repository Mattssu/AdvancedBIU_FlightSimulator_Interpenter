//
// Created by lab on 12/23/18.
//

#include "WhileCommand.h"

void WhileCommand::doCommand() {
    while (isValid()) {
        for (Expression *c: commands) {
            c->calculate();
        }
    }
}

WhileCommand::~WhileCommand() {
    for (Expression *c: commands) {
        delete (c);
    }
    //delete (this);
}