cmake_minimum_required(VERSION 3.13)
project(Ex3)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS -pthread)

add_executable(Ex3 main.cpp Command.cpp Command.h OpenDataCommand.cpp OpenDataCommand.h ConnectCommand.cpp ConnectCommand.h dataHandler.cpp dataHandler.h outputHandler.cpp outputHandler.h VarCommand.cpp VarCommand.h AssignCommand.cpp AssignCommand.h dataParser.cpp dataParser.h CommandExpression.cpp CommandExpression.h CommandsFactory.h ConnectCommandFactory.h AssignCommandFactory.h OpenDataCommandFactory.h VarCommandFactory.h ConditionCommand.cpp ConditionCommand.h IfConCommand.cpp IfConCommand.h IfCommandFactory.h WhileCommand.cpp WhileCommand.h WhileFactory.h Number.h Mul.h Minus.h Div.h Plus.h stringToExpression.cpp stringToExpression.h PrintCommandFactory.h PrintCommand.cpp PrintCommand.h SleepCommand.h SleepCommandFactory.h)