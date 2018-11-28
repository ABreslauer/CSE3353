//
// Created by Andrew on 11/5/2018.
//

#ifndef LAB3_INTERFACEINTERFACE_H
#define LAB3_INTERFACEINTERFACE_H

#include <string>
#include "Graph.h"

class interfaceInterface {
public:
    virtual void saveStats(std::string algoType, int nodeNum, int permutationNum, double dist) = 0;
    virtual void statsToFile(std::string outFile) = 0;
    virtual void execute(Graph& g) = 0;
};

#endif //LAB3_INTERFACEINTERFACE_H
