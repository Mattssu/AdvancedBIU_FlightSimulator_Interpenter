//
// Created by lab on 12/21/18.
//

#ifndef EX3_SETVARCOMMAND_H
#define EX3_SETVARCOMMAND_H


#include <vector>
#include <string>
#include "Command.h"

using namespace std;

/**
* Sets the command Assign which
* sets a value to an existing Var
*/
class AssignCommand : public Command {
private:
    vector<string> param;
public:
    /**
    * Constructor.
    */
    AssignCommand(vector<string> params);

    /**
    * Sets the command Assign which
    * sets a value to an existing Var
    */
    void doCommand();

    ~AssignCommand() {};
};


#endif //EX3_SETVARCOMMAND_H
