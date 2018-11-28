//
// Created by Andrew on 11/27/2018.
//

#ifndef LAB4_TABU_H
#define LAB4_TABU_H

#include "TSPInterface.h"
#include <vector>

class Tabu : public TSPInterface {
    std::vector<Solution> solutions;
    std::vector<Solution> tabuList;
    int iterNum = 5000;
    int listSize = 10;
    Solution findNeighbor(Solution best, Graph& g);
    bool contains(Solution s);
    Solution getMin();
public:
    Tabu();
    void execute(Graph& g) override;
    void setListSize(int num);
};

#endif //LAB4_TABU_H
