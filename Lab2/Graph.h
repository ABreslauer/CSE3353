//
// Created by Andrew on 9/11/2018.
//

#ifndef LAB2_GRAPH_H
#define LAB2_GRAPH_H

#include <vector>
#include <string>

class Graph {
    struct Node {
        int label = -999;
        std::vector<int> paths;

        Node(int nodeLabel, std::vector<int>pathVec) : label(nodeLabel), paths(pathVec) {};
    };

    std::vector<Node> nodes;
    std::vector<std::vector<int>> weights;
    std::vector<std::vector<int>> positions;
    std::vector<std::vector<int>> matrix;
    int numOfNodes;
    bool isAMatrix = false;

public:
    Graph(int num);
    Graph();
    Graph& operator=(const Graph& rhs);
    void loadNodes(std::string inFile);
    void loadNodesMatrix(std::string inFile);
    void loadWeights(std::string inFile);
    void loadPositions(std::string inFile);

    std::vector<int> getPaths(int nodeLabel);
    int getWeight(int source, int destination);
    double getDistance(int source, int destination);
    int getSize();

    bool isMatrix();
    bool isPath(int source, int destination);
};

#endif //LAB2_GRAPH_H
