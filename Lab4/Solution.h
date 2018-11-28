//
// Created by Andrew on 11/27/2018.
//

#ifndef LAB4_SOLUTION_H
#define LAB4_SOLUTION_H

#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "Graph.h"

class Solution {
    std::vector<int> path;
    float score;
public:
    Solution(Graph& g);
    void initPath(Graph& g);
    void updateScore(Graph& g);
    float getScore();
    int getLength();
    void swapSolution(int i, int j, Graph& g);
    std::vector<int> getPath();
    bool operator==(const Solution& rhs);
    bool isValid();
    void setPath(std::vector<int>& newPath);
    Solution& operator=(const Solution& rhs);
};

#endif //LAB4_SOLUTION_H
