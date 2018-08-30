//
// Created by Andrew on 8/29/2018.
//

#ifndef LAB1_SORT_H
#define LAB1_SORT_H

#include <tuple>
#include <chrono>
#include "algorithm.h"

class sort : public algorithm {
protected:
    std::string type = "Sort";
    std::tuple<double, std::string, int> stats;
public:
    enum SortingAlgorithms {
        Bubble, Insertion, Merge
    };
    sort();
    void saveStats(double time, std::string type);
    std::tuple<double, std::string, int> getStats();
    std::vector<int> getNums();
    ~sort() {}
};

#endif //LAB1_SORT_H
