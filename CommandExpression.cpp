//
// Created by lab on 12/22/18.
//

#include "CommandExpression.h"

CommandExpression::CommandExpression(Command *c) {
    cmd = c;
}

double CommandExpression::calculate() {
    cmd->doCommand();
}
