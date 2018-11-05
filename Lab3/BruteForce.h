//
// Created by Andrew on 10/28/2018.
//

#ifndef LAB3_BRUTEFORCE_H
#define LAB3_BRUTEFORCE_H

#include "TSPInterface.h"
#include "Graph.h"
#include <deque>
#include <vector>

class BruteForce : public TSPInterface {
public:
    BruteForce();
    void execute(Graph& g) override;
    void getAllPermutations(std::vector<int> vec, int curr, int max, Graph& g);
    void swap(std::vector<int>& vec, int p1, int p2);
};

#endif //LAB3_BRUTEFORCE_H
