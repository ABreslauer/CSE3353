//
// Created by Andrew on 10/31/2018.
//

#include "DynamicProgramming.h"
#include <fstream>
#include <iostream>

DynamicProgramming::DynamicProgramming(const std::string& inFile) {
    read(inFile);
    wtfIsGoingOn();
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
        formMatrix();
    }
    else {
        std::cout << "File not found" << std::endl;
    }

}

void DynamicProgramming::formMatrix() {
    std::vector<double> temp;
    for (int i = 0; i < nodeVec.size(); i++) {
        nodeMatrix.push_back(temp);
        for (int j = 0; j < nodeVec.size(); j++) {
            nodeMatrix[i].push_back(nodeVec[i].getDist(nodeVec[j]));
        }
    }
}

void DynamicProgramming::wtfIsGoingOn() {
    Node nearestCity {};
    Node visitedCities[10];
    double cost;
    for (int i = 0; i < nodeMatrix.size(); i++) {

    }
}