#include "stringToExpression.h"
#include "dataParser.h"

/**
 * init the priority of the operators.
 */
void stringToExpression::initProOfOp() {
    proOfOp.insert(pair<char, int>('+', 1));
    proOfOp.insert(pair<char, int>('-', 1));
    proOfOp.insert(pair<char, int>('*', 2));
    proOfOp.insert(pair<char, int>('/', 2));
    proOfOp.insert(pair<char, int>('(', 0));
    proOfOp.insert(pair<char, int>(')', 0));
    //proOfOp.insert(pair<char,int>('=',-1));
}

/**
 * checks if char is an operator
 */
bool isOperator(char t) {
    if (t == '+' || t == '*' || t == '/' || t == '(' || t == ')' || t == '=' || t == '-') {
        return true;
    }
    return false;
}

/**
 * do the shutinYardAlgo and return  the value.
 */
double stringToExpression::ShunYardAlgo() {
    preProcessToken();
    //
    string num = "";
    bool isNum = false;
    //bool enteredNum= false;
    stack<char> stac;
    queue<string> que;
    bool isNumNeg = false;// here
    //loop
    for (int i = 0; i < token.length(); i++) {

        if (token[i] >= '0' && token[i] <= '9') {
            if (isNum) {
                num += to_string(token[i] - '0');
            } else {
                isNum = true;
                //enteredNum= true;
                num = to_string(token[i] - '0');
            }
        } else if (token[i] == '.' && isNum) {
            num += token[i];
        } else { // not a number
            if (isNum/*&&enteredNum*/) {
                isNum = false;
                //here
                if (isNumNeg) {
                    num = "-" + num;
                    isNumNeg = false;
                }
                que.push(num);
            }
            if (token[i] == ' ' || token[i] == '(' || token[i] == ')') {
                // do noting if ' ' or ')[
                // push ( in case of '('
                if (token[i] == '(') {
                    stac.push('(');
                }
                if (token[i] == ')') {
                    // if ")" so do like the algo should do :
                    //If it''s a right bracket
                    //   while there is not a left bracket at the top of the stack.
                    //       pop operators from the stack into the output queue
                    //  pop the left bracket from the stack and discard it.
                    char topOfStack = stac.top();
                    string popStack = "";
                    while (topOfStack != '(') {
                        popStack += topOfStack;
                        que.push(popStack);
                        stac.pop();
                        topOfStack = stac.top();
                        popStack = "";
                    }
                    stac.pop();
                }

            } else {
                char t = token[i];
                if (t == '+' || t == '*' || t == '/' || t == '(' || t == ')' || t == '=' || t == '-') {
                    if (t == '-') {
                        // check if it is neg number of operator .
                        if (i == 0) {
                            isNumNeg = true;
                        } else if (isOperator(token[i - 1])) {
                            isNumNeg = true;
                        }
                    }
                    if (isNumNeg) {
                        //this will exit us from the main if .
                        // in case that the number is not neg we want to continue.
                    } else {
                        int value = proOfOp[t];//check
                        if (stac.empty()) {
                            stac.push(t);
                        } else {
                            int topValue = proOfOp[stac.top()];
                            if (value > topValue) {
                                stac.push(t);
                            } else {
                                // do the pop
                                do {
                                    string s = "";
                                    s += stac.top();
                                    stac.pop();
                                    que.push(s);
                                    if (!stac.empty()) {
                                        topValue = proOfOp[stac.top()];
                                    }
                                } while (value < topValue && !stac.empty());
                                stac.push(t);
                            }
                        }
                    }
                } else {
                    // throw error
                }

            }
        }
    }
    //after has ended to enter last num
    if (isNum/*&&enteredNum*/) {
        if (isNumNeg) {
            num = "-" + num;
        }
        que.push(num);
    }
    // now we will push all the  stack to the queue .
    while (!stac.empty()) {
        if (stac.top() == '(') {
            stac.pop();
        } else {
            string q = "";
            q += stac.top();
            stac.pop();
            que.push(q);
        }
    }

    string plus = "";
    string minus = "";
    string div = "";
    string mult = "";
    plus += "+";
    minus += "-";
    div += "/";
    mult += "*";
    stack<Expression *> revstack;
    while (!que.empty()) {
        string top = que.front();
        try {
            double var = stod(top);
            /*
            if (isNumNeg) {
                var = -var;
            }
            */
            revstack.push(new Number(var));
            que.pop();
        } catch (...) {
            Expression *func;
            if (top == minus) {
                Expression *right = revstack.top();
                revstack.pop();
                if (!revstack.empty()) {
                    Expression *left = revstack.top();
                    revstack.pop();
                    func = new Minus(left, right);
                } else { // in case of neg number .
                    Expression *zero = new Number(0);
                    func = new Minus(zero, right);
                }
                revstack.push(func);
                que.pop();
            }
            if (top == plus || top == div || top == mult) {
                Expression *right = revstack.top();
                revstack.pop();
                Expression *left = revstack.top();
                revstack.pop();
                if (top == plus) {
                    func = new Plus(left, right);
                    /* } else if (top == minus) {
                         func = new Minus(left, right);*/
                } else if (top == div) {
                    func = new Div(left, right);
                } else {
                    func = new Mul(left, right);
                }
                revstack.push(func);
                que.pop();
            } else {
                // error
                throw invalid_argument("WRONG STRING");
            }
        }
    }
    double result = revstack.top()->calculate();
    //releases resources
    while (!revstack.empty()) {
        Expression *e = revstack.top();
        revstack.pop();
        delete (e);
    }
    return result;
}

/**
 * makes a pre process for the algo to work
 */
void stringToExpression::preProcessToken() {
    //Var name to Value swap
    dataParser *dp = new dataParser;
    vector<string> temp = dp->lexer(token);
    for (auto it = temp.begin(); it != temp.end(); ++it) {
        //can make it faster with isOperator
        (*it) = dp->fill((*it));
    }
    temp = dp->paramMaker(temp);
    token = temp[0];
    delete (dp);
}



