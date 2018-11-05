//
// Created by Andrew on 11/5/2018.
//

#include <cmath>
#include "Graph.h"

void Graph::loadNodes(std::string inFile) {
    std::ifstream input;
    input.open(inFile);

    if(input.is_open()) {
        int num;
        double doubleVal;
        std::string val;

        while(!input.eof()) {
            int pos = 0;
            getline(input, val);
            if(val.size() > 0) {
                Node n;
                pos = val.find(',');
                num = stoi(val.substr(0, pos));
                val.erase(0, pos+1);
                n.num = num;
                for (int i = 0; i < 3; i++) {
                    pos = val.find(',');
                    doubleVal = stof(val.substr(0, pos));
                    val.erase(0, pos+1);
                    n.coordinates[i] = doubleVal;
                }
                nodeVec.push_back(n);
                nodeNum++;
            }
        }
        input.close();
    }
    else {
        std::cout << "File: " << inFile << " failed to open." << std::endl;
    }
}

double Graph::getDist(int place1, int place2) {
    Node n1 = nodeVec[place1-1];
    Node n2 = nodeVec[place2-1];
    double dist = 0;
    for (int i = 0; i < 3; i++) {
        dist += pow(n1.coordinates[i] - n2.coordinates[i], 2);
    }
    return cbrt(dist);
}

int Graph::getNodeNum() {
    return nodeNum;
}