//
// Created by Andrew on 9/11/2018.
//

#ifndef LAB2_SEARCH_H
#define LAB2_SEARCH_H

#include "Algorithm.h"
#include <iostream>

class Search : public Algorithm {
protected:
    std::vector<int> path;
    double numNodes = 0;
    std::tuple<Algorithm::searchTypes, double, int, int, int, std::vector<int>, double, int, bool> stat;
    searchTypes selectedAlgorithm = Algorithm::END;

public:
    void saveStats(Algorithm::searchTypes type, double time, int start, int end, int numNodes, std::vector<int> finalPath, double distance, double num, bool isMatrix);

    void selectAlgo(searchTypes types) override;

    void printStats() override;

    void statsToFile(std::string fileName) override;

    void execute(int start, int end, Graph &graph) override;

    void normalize() override;
};
#endif //LAB2_SEARCH_H
