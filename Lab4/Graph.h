//
// Created by Andrew on 11/5/2018.
//

#ifndef LAB3_GRAPH_H
#define LAB3_GRAPH_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Graph {
private:
    int nodeNum = 0;
    struct Node {
        int num;
        double coordinates[3];
    };
    std::vector<Node> nodeVec;
public:
    double getDist(int place1, int place2);
    void loadNodes(std::string inFile);
    int getNodeNum();
};

#endif //LAB3_GRAPH_H
