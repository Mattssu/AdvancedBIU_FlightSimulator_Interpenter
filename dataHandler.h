//
// Created by lab on 12/21/18.
//

#ifndef EX3_DATAHANDLER_H
#define EX3_DATAHANDLER_H

#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
/**
 * the maps are static to be able to instanced and updated
 * from different places through the code.
 */
static map<string, string> nameToPath; // binds
static map<string, string> nonXmlPath; // non xml binds
static map<string, double> nameToValue;//symbolTable
static map<string, double> pathToValue; //address to Value

/**
 * A sort of static class that handles all the
 * data that we get from the Simulator aswell as
 * from the user or file
 */
class dataHandler {
public:
    /**
     * function that updates the maps
     */
    static void updater();

    /**
     * initialises the PathToValue Map
     */
    static void initPathToValue();

    /**
     * returns NameToValue map
     */
    static map<string, double> getValueMap();

    //static map<string, double> getTestMap();

    //static map<string, string> getTestPath();

    /**
     * returns specific NameToPath if exists
     */
    static string *getNameToPath(string str);

    /**
     * returns specific NameToNonXMlPath if exists
     */
    static string *getNameToNonXmlPath(string str);

    /**
     * returns specific NameToValue if exists
     */
    static double *getNameToValue(string str);

    /**
     * returns specific PathTOValue if exists
     */
    static double *getPathToValue(string path);

    /**
     * adds or updates the specific map
     */
    static void addNonXmlToPath(string name, string path);

    /**
     * adds or updates the specific map
     */
    static void addNameToPath(string name, string path);

    /**
     * adds or updates the specific map
     */
    static void addNameToValue(string name, double value);

    /**
     * adds or updates the specific map
     */
    static void addPathToValue(vector<double> list);
};


#endif //EX3_DATAHANDLER_H
