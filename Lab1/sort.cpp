//
// Created by Andrew on 8/29/2018.
//
#include "bubbleSort.h"
#include "sort.h"

sort::sort() {}

void sort::saveStats(double time, std::string str) {
    stats = {time, str, nums.size()};
}

std::tuple<double, std::string, int> sort::getStats() {
    return stats;
};

std::vector<int> sort::getNums() {
    return nums;
}