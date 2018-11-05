//
// Created by Andrew on 10/28/2018.
//
#include "BruteForce.h"

BruteForce::BruteForce() {
    type = 0;
}

void BruteForce::execute(Graph &g) {
    std::vector<int> vec;
    attemptNum = 0;
    bestPath = 100000;
    for (int i = 0; i < 3; i++) {
        vec.push_back(i);
    }
    getAllPermutations(vec, 0, vec.size()-1, g);
    this->saveStats(types[this->type], g.getNodeNum(), attemptNum, bestPath);
}

void BruteForce::getAllPermutations(std::vector<int> vec, int curr, int max, Graph &g) {
    if(curr==max) {
        double sum = 0;
        for (int i = 0; i < vec.size()-1; i++) {
            sum += g.getDist(vec[i], vec[i+1]);
        }
        sum += g.getDist(vec[vec.size()-1], vec[0]);
        attemptNum++;
        if (sum < bestPath) {
            bestPath = sum;
            vec.push_back(vec[0]);
            path = vec;
        }
    }
    else {
        for (int i = curr; i <= max; i++) {
            swap(vec, curr, i);
            getAllPermutations(vec, curr+1, max, g);
            swap(vec, curr, i);
        }
    }
}

void BruteForce::swap(std::vector<int> &vec, int p1, int p2) {
    int temp = vec[p1];
    vec[p1] = vec[p2];
    vec[p2] = temp;
}