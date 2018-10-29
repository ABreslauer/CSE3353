//
// Created by Andrew on 10/28/2018.
//
#include "BruteForce.h"
#include <fstream>
#include <iostream>
#include <algorithm>

BruteForce::BruteForce() {}

BruteForce::BruteForce(const std::string& inFile) {
    read(inFile);
}

void BruteForce::read(std::string inFile) {
    std::string temp1, temp2, temp3, temp4 {};
    int nodeNum;
    float nodeX, nodeY, nodeZ {};

    std::fstream input;
    input.open(inFile);
    if (input.is_open()) {
        while(input.good()) {
            input >> temp1 >> temp2 >> temp3 >> temp4;
            nodeNum = stoi(temp1);
            nodeX = stof(temp2);
            nodeY = stof(temp3);
            nodeZ = stof(temp4);
            Node n(nodeNum, nodeX, nodeY, nodeZ);
            nodeVec.push_back(n);
        }
    }
    else {
        std::cout << "File not found" << std::endl;
    }
}

void BruteForce::doTSP() {
    do {
        totalPermutations++;
        double temp = getPathLength();
        if (temp < shortestPathLength) {
            shortestPathLength = temp;
            shortestPathNodes = nodeVec;
            std::cout << "Updated shortest path: " << shortestPathLength << std::endl;
        }
    } while(std::next_permutation(nodeVec.begin(), nodeVec.end()));
}

double BruteForce::getPathLength() {
    double pathLength {};
    for (int i = 0; i < nodeVec.size()-1; i++) {
        pathLength += nodeVec[i].getDist(nodeVec[i+1]);
    }
    return pathLength;
}

std::vector<Node> BruteForce::getShortestPathNodes() {
    return shortestPathNodes;
}

double BruteForce::getShortestPathLength() {
    return shortestPathLength;
}

long BruteForce::getTotalPermutations() {
    return totalPermutations;
}