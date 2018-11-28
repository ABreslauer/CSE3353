//
// Created by Andrew on 11/5/2018.
//

#ifndef LAB3_TSPINTERFACE_H
#define LAB3_TSPINTERFACE_H

#include "Graph.h"
#include <vector>
#include <string>
#include "interfaceInterface.h"
#include "Solution.h"

class TSPInterface : public interfaceInterface {
    enum TSPMethod {BruteForce, DP, TSPTabu, TSPGenetic};
    struct Stat {
        std::string algoType;
        int nodeNum;
        int permutationNum;
        double dist;
    };
    std::vector<Stat> stats;
protected:
    std::string types[4] = {"Brute Force", "Dynamic Programming", "Tabu", "Genetic"};
    int attemptNum = 0;
    double bestPath = 0;
    int type = -1;
    std::vector<int> path;
public:
    void saveStats(std::string algoType, int nodeNum, int permutationNum, double dist);
    void statsToFile(std::string outFile);
    virtual void execute(Graph& g) = 0;

};

#endif //LAB3_TSPINTERFACE_H
