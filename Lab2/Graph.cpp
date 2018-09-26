//
// Created by Andrew on 9/11/2018.
//

#include "Graph.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <sstream>
#include <iterator>

Graph::Graph(int num) {
    numOfNodes = num;
}

Graph::Graph() {
    numOfNodes = -1;
}

Graph& Graph::operator=(const Graph& rhs) {
    this->numOfNodes = rhs.numOfNodes;
    this->positions = rhs.positions;
    this->weights = rhs.weights;
    this->nodes = rhs.nodes;
    this->matrix = rhs.matrix;
}

void Graph::loadNodes(std::string inFile) {
    std::ifstream input;
    input.open(inFile);
    std::string value;
    std::string inputSplit = ",";

    if(input.is_open()){
        std::vector<int> paths;
        int label;
        while(!input.eof()) {
            int pos = 0;
            std::getline(input, value);
            std::string path;
            pos = value.find(inputSplit);
            label = stoi(value.substr(0, pos));
            value.erase(0, pos + inputSplit.length());
            while((pos = value.find(inputSplit)) != std::string::npos){
                path = value.substr(0, pos);
                value.erase(0, pos + inputSplit.length());
                paths.push_back(stoi(path));
            }
            paths.push_back(stoi(value));
            Node n = {label, paths};
            nodes.push_back(n);
            paths.clear();
        }
    }

    else {
        std::cout << "File: " << inFile << " failed to open properly." << std::endl;
    }
}

void Graph::loadNodesMatrix(std::string inFile) {
    std::ifstream input;
    input.open(inFile);
    isAMatrix = true;
    std::string value;
    std::string inputSplit = ",";

    for (int i = 0; i < numOfNodes; i++) {
        std::vector<int> vec;
        matrix.push_back(vec);
        for (int j = 0; j < numOfNodes; j++) {
            matrix[i].push_back(0);
        }
    }

    if(input.is_open()) {
        std::string nodeLabel;
        int lineNum {};
        while(!input.eof()) {
            std::getline(input, value);

            int pos = 0;
            pos = value.find(inputSplit);
            value.erase(0, pos + inputSplit.length());
            std::stringstream ss(value);
            std::vector<int> vals;
            while(std::getline(ss, nodeLabel, ',')){
                vals.push_back(stoi(nodeLabel));
            }
            for(int i = 0; i < vals.size(); i++){
                matrix[lineNum][vals[i] - 1] = 1;
            }
            lineNum++;
        }
    }
    else {
        std::cout << "File: " << inFile << " failed to open properly." << std::endl;
    }
}

void Graph::loadPositions(std::string inFile) {
    std::ifstream input;
    input.open(inFile);
    std::string value;
    std::string inputSplit = ",";

    if (input.is_open()) {
        for (int i = 0; i < numOfNodes; i++) {
            std::vector<int> vec;
            positions.push_back(vec);
            for (int j = 0; j < 4; j++) {
                positions[i].push_back(0);
            }
        }

        int nodeLabel;
        int lineNum {};
        while(!input.eof()) {
            int position {};
            std::getline(input, value);
            for (int i = 0; i < 4; i++) {
                position = value.find(inputSplit);
                nodeLabel = stoi(value.substr(0, position));
                value.erase(0, position + inputSplit.length());
                positions[lineNum][i] = nodeLabel;
            }
            lineNum++;
        }
    }

    else {
        std::cout << "File: " << inFile << " failed to open properly." << std::endl;
    }
}

void Graph::loadWeights(std::string inFile) {
    std::ifstream input;
    input.open(inFile);
    std::string value;
    std::string inputSplit = ",";
    if (input.is_open()) {
        int nodeLabel;
        int lineNum {};
        while(!input.eof()) {
            int position {};
            std::vector<int> vec;
            weights.push_back(vec);
            for(int j = 0; j < 3; j++) {
                weights[lineNum].push_back(0);
            }
            std::getline(input, value);
            for(int i = 0; i < 3; i++) {
                position = value.find(inputSplit);
                nodeLabel = stoi(value.substr(0, position));
                value.erase(0, position + inputSplit.length());
                weights[lineNum][i] = nodeLabel;
            }
            lineNum++;
        }
    }
    else {
        std::cout << "File: " << inFile << " failed to open properly." << std::endl;
    }
}

double Graph::getDistance(int source, int destination) {
    int sourceLocation[3];
    int destLocation[3];

    for (int i = 0; i < 3; i++) {
        sourceLocation[i] = positions[source - 1][i + 1];
        destLocation[i] = positions[destination - 1][i + 1];
    }
    int squared {};
    for (int i = 0; i < 3; i++) {
        squared += pow(sourceLocation[i] - destLocation[i], 2);
    }
    return sqrt(squared);
}

int Graph::getWeight(int source, int destination) {
    for(int i = 0; i < weights.size(); i++) {
        if(weights[i][0] == source && weights[i][1] == destination) {
            return weights[i][2];
        }
    }
    return -1;
}

std::vector<int> Graph::getPaths(int nodeLabel) {
    if(isAMatrix){
        std::vector<int> matrixPaths;
        for(int i = 0; i < matrix[nodeLabel - 1].size(); i++) {
            if (matrix[nodeLabel - 1][i] != 0) {
                matrixPaths.push_back(i + 1);
            }
        }
        return matrixPaths;
    }
    else
    return nodes[nodeLabel - 1].paths;
}

int Graph::getSize() {
    return numOfNodes;
}

bool Graph::isMatrix() {
    return isAMatrix;
}

bool Graph::isPath(int source, int dest) {
    if(!isAMatrix) {
        for (int i = 0; i < numOfNodes; i++) {
            if (nodes[i].label == source) {
                for (int j = 0; j < nodes[i].paths.size(); j++) {
                    if (nodes[i].paths[j] == dest)
                        return true;
                }
            }
        }
    }
    else{
        std::vector<int> p = this->getPaths(source);
        for(int i = 0; i < p.size(); i++){
            if(p[i] == dest)
                return true;
        }
    }
    return false;
}










