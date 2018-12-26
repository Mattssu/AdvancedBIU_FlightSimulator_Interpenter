//
// Created by lab on 12/23/18.
//

#include "IfConCommand.h"

void IfConCommand::doCommand() {
    if (isValid()) {
        for (Expression *c: commands) {
            c->calculate();
        }
    }
}

IfConCommand::~IfConCommand() {
    for (Expression *c: commands) {
        delete (c);
    }
    //delete (this);
}