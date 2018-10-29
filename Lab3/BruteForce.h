//
// Created by Andrew on 10/28/2018.
//

#ifndef LAB3_BRUTEFORCE_H
#define LAB3_BRUTEFORCE_H

#include "Node.h"
#include <vector>
#include <cfloat>

class BruteForce {
private:
    std::vector<Node> nodeVec;
    double shortestPathLength = DBL_MAX;
    std::vector<Node> shortestPathNodes;
    long totalPermutations {};
public:
    BruteForce();
    explicit BruteForce(const std::string& inFile);
    void read(std::string inFile);

    void doTSP();
    double getPathLength();

    std::vector<Node> getShortestPathNodes();
    double getShortestPathLength();
    long getTotalPermutations();
};

#endif //LAB3_BRUTEFORCE_H
