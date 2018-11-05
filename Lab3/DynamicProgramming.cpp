//
// Created by Andrew on 10/31/2018.
//

#include "DynamicProgramming.h"
#include <cmath>
#include <algorithm>
#include <fstream>
#include <iostream>

DynamicProgramming::DynamicProgramming(const std::string& inFile) {
    read(inFile);
}

void DynamicProgramming::read(const std::string& inFile) {
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

void DynamicProgramming::doTSP() {
    std::vector<int> vec;
    for (int i = 1; i < nodeVec.size(); i++) {
        vec.push_back(nodeVec[i].getNum());
    }
    shortestPathNodes.push_back(nodeVec[0]);
    shortestPathLength = findPath(1, vec, 1, nodeVec);
    shortestPathNodes.push_back(nodeVec[0]);
    std::cout << totalPermutations << " " << pow(nodeVec.size(), 2) * pow(2, nodeVec.size()) << std::endl;
    std::cout << "Size of sPN: " << shortestPathNodes.size() << std::endl;
    for (int i = 0; i < shortestPathNodes.size(); i++) {
        if (i == shortestPathNodes.size()-1) {
            std::cout << shortestPathNodes[i].getNum();
        } else {
            std::cout << shortestPathNodes[i].getNum() << ", ";
        }
    }

    std::cout << std::endl;
}

double DynamicProgramming::findPath(int start, std::vector<int> values, int end, std::vector<Node> nodeVec) {
    if (values.empty()) {
        totalPermutations++;
        return nodeVec[start].getDist(nodeVec[end]);
    }
    else {
        std::vector<double> sum;
        for (int i = 0; i < values.size(); i++) {
            std::vector<int> temp = values;
            temp.erase(temp.begin() + i);
            double min = 10000;
            int minIndex = 0;
            for (int j = 2; j <= nodeVec.size(); j++) {
                if(nodeVec[start].getDist(nodeVec[j]) < min) {
                    min = nodeVec[start].getDist(nodeVec[j]);
                    minIndex = j;
                }
            }
            if (!(count(shortestPathNodes.begin(), shortestPathNodes.end(), minIndex))) {
                shortestPathNodes.push_back(nodeVec[minIndex-1]);
            }
            //totalPermutations++;
            sum.push_back((nodeVec[start].getDist(nodeVec[i]) + findPath(values[i], temp, end, nodeVec)));
        }
        double min = 10000;
        for (int i = 0; i < sum.size(); i++) {
            if (sum[i] < min) {
                min = sum[i];
            }
        }
        return min;
    }
}