//
// Created by lab on 12/21/18.
//

#include "dataHandler.h"
#include <vector>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

/**
 * function that updates the maps
 */
void dataHandler::updater() {
    pthread_mutex_lock(&lock);
    //static map<string, double> p;
    //p = dataHandler::getTestMap();
    //static map<string, string> d;
    //d = dataHandler::getTestPath();

    //goes over the name to path
    for (auto it = nameToPath.begin(); it != nameToPath.end(); ++it) {
        string t = (*it).second;
        //t = t.substr(1, t.size() - 2);
        //t = t + "\"";

        //checks if such path has a value
        if (pathToValue.find(t) != pathToValue.end()) {
            double num = pathToValue.at(t);
            t = (*it).first;
            //updates it
            addNameToValue(t, num);
        }
    }
    pthread_mutex_unlock(&lock);
}

//GET FUNCS
/**
 * returns NameToValue map
 */
map<string, double> dataHandler::getValueMap() {
    updater();
    //static map<string, double> p;
    //p = nameToValue;
    return nameToValue;
}

/**
 * returns specific NameToPath if exists
 */
string *dataHandler::getNameToPath(string str) {
    //goes over the map
    for (auto it = nameToPath.begin(); it != nameToPath.end(); ++it) {
        if ((*it).first == str) {
            return &(*it).second;
        }
    }
    return nullptr;
}

/**
 * returns specific NameToNonXMlPath if exists
 */
string *dataHandler::getNameToNonXmlPath(string str) {
    //goes over the map
    for (auto it = nonXmlPath.begin(); it != nonXmlPath.end(); ++it) {
        if ((*it).first == str) {
            return &(*it).second;
        }
    }
    //error
    return nullptr;
}

/**
 * returns specific NameToValue if exists
 */
double *dataHandler::getNameToValue(string str) {
    updater();
    //goes over the map
    for (auto it = nameToValue.begin(); it != nameToValue.end(); ++it) {
        if ((*it).first == str) {
            return &(*it).second;
        }
    }
    //if not there
    return nullptr;
}

/**
 * returns specific PathTOValue if exists
 */
double *dataHandler::getPathToValue(string path) {
    updater();
    //goes over the map
    for (auto it = pathToValue.begin(); it != pathToValue.end(); ++it) {
        if ((*it).first == path) {
            return &(*it).second;
        }
    }
    //if cant find
    return nullptr;
}

//ADD AND UPDATE FUNCS
/*
map<string, double> dataHandler::getTestMap() {
    //updater();
    return pathToValue;
}

map<string, string> dataHandler::getTestPath() {
    //updater();
    return nameToPath;
}
 */

/**
 * adds or updates the specific map
 */
void dataHandler::addNonXmlToPath(string name, string path) {
    nonXmlPath[name] = path;
}

/**
 * adds or updates the specific map
 */
void dataHandler::addPathToValue(vector<double> list) {
    pathToValue.at("/instrumentation/airspeed-indicator/indicated-speed-kt") = list[0];
    pathToValue.at("/instrumentation/altimeter/indicated-altitude-ft") = list[1];
    pathToValue.at("/instrumentation/altimeter/pressure-alt-ft") = list[2];
    pathToValue.at("/instrumentation/attitude-indicator/indicated-pitch-deg") = list[3];
    pathToValue.at("/instrumentation/attitude-indicator/indicated-roll-deg") = list[4];
    pathToValue.at("/instrumentation/attitude-indicator/internal-pitch-deg") = list[5];
    pathToValue.at("/instrumentation/attitude-indicator/internal-roll-deg") = list[6];
    pathToValue.at("/instrumentation/encoder/indicated-altitude-ft") = list[7];
    pathToValue.at("/instrumentation/encoder/pressure-alt-ft") = list[8];
    pathToValue.at("/instrumentation/gps/indicated-altitude-ft") = list[9];
    pathToValue.at("/instrumentation/gps/indicated-ground-speed-kt") = list[10];
    pathToValue.at("/instrumentation/gps/indicated-vertical-speed") = list[11];
    pathToValue.at("/instrumentation/heading-indicator/indicated-heading-deg") = list[12];
    pathToValue.at("/instrumentation/magnetic-compass/indicated-heading-deg") = list[13];
    pathToValue.at("/instrumentation/slip-skid-ball/indicated-slip-skid") = list[14];
    pathToValue.at("/instrumentation/turn-indicator/indicated-turn-rate") = list[15];
    pathToValue.at("/instrumentation/vertical-speed-indicator/indicated-speed-fpm") = list[16];
    pathToValue.at("/controls/flight/aileron") = list[17];
    pathToValue.at("/controls/flight/elevator") = list[18];
    pathToValue.at("/controls/flight/rudder") = list[19];
    pathToValue.at("/controls/flight/flaps") = list[20];
    pathToValue.at("/controls/engines/current-engine/throttle") = list[21];
    pathToValue.at("/engines/engine/rpm") = list[22];
    /*
    static map<string, double> p;
    p = dataHandler::getTestMap();
    p = dataHandler::getTestMap();
     */
}

/**
 * adds or updates the specific map
 */
void dataHandler::addNameToPath(string name, string path) {
    nameToPath[name] = path;
}

/**
 * adds or updates the specific map
 */
void dataHandler::addNameToValue(string name, double value) {
    //
    nameToValue[name] = value;
}

/**
 * initialises the PathToValue Map
 */
void dataHandler::initPathToValue() {
    //sets the map to get corresponding values from simulator
    pathToValue.insert(pair<string, double>("/instrumentation/airspeed-indicator/indicated-speed-kt", 0));
    pathToValue.insert(pair<string, double>("/instrumentation/altimeter/indicated-altitude-ft", 0));
    pathToValue.insert(pair<string, double>("/instrumentation/altimeter/pressure-alt-ft", 0));
    pathToValue.insert(pair<string, double>("/instrumentation/attitude-indicator/indicated-pitch-deg", 0));
    pathToValue.insert(pair<string, double>("/instrumentation/attitude-indicator/indicated-roll-deg", 0));
    pathToValue.insert(pair<string, double>("/instrumentation/attitude-indicator/internal-pitch-deg", 0));
    pathToValue.insert(pair<string, double>("/instrumentation/attitude-indicator/internal-roll-deg", 0));
    pathToValue.insert(pair<string, double>("/instrumentation/encoder/indicated-altitude-ft", 0));
    pathToValue.insert(pair<string, double>("/instrumentation/encoder/pressure-alt-ft", 0));
    pathToValue.insert(pair<string, double>("/instrumentation/gps/indicated-altitude-ft", 0));
    pathToValue.insert(pair<string, double>("/instrumentation/gps/indicated-ground-speed-kt", 0));
    pathToValue.insert(pair<string, double>("/instrumentation/gps/indicated-vertical-speed", 0));
    pathToValue.insert(pair<string, double>("/instrumentation/heading-indicator/indicated-heading-deg", 0));
    pathToValue.insert(pair<string, double>("/instrumentation/magnetic-compass/indicated-heading-deg", 0));
    pathToValue.insert(pair<string, double>("/instrumentation/slip-skid-ball/indicated-slip-skid", 0));
    pathToValue.insert(pair<string, double>("/instrumentation/turn-indicator/indicated-turn-rate", 0));
    pathToValue.insert(pair<string, double>("/instrumentation/vertical-speed-indicator/indicated-speed-fpm", 0));
    pathToValue.insert(pair<string, double>("/controls/flight/aileron", 0));
    pathToValue.insert(pair<string, double>("/controls/flight/elevator", 0));
    pathToValue.insert(pair<string, double>("/controls/flight/rudder", 0));
    pathToValue.insert(pair<string, double>("/controls/flight/flaps", 0));
    pathToValue.insert(pair<string, double>("/controls/engines/current-engine/throttle", 0));
    pathToValue.insert(pair<string, double>("/engines/engine/rpm", 0));
}