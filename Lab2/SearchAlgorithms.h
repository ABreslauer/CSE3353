//
// Created by Andrew on 9/11/2018.
//

#ifndef LAB2_SEARCHALGORITHMS_H
#define LAB2_SEARCHALGORITHMS_H

#include "Search.h"
#include <queue>

class SearchAlgorithms : public Search {
    std::vector<int> path;
public:
    void execute(Search *search, Graph &graph, int start, int end);
    double DFSSetup(int start, int end, Graph &graph);
    double BFSSetup(int start, int end, Graph &graph);
    void BFS(int node, int end, std::queue<int> &queue, std::vector<bool> discovered, Graph &graph, double &dist);
    double BFSIterative(int start, int end, Graph &graph);
    double DFSIterative(int start, int end, Graph &graph);
    void DFS(int node, int end, bool visited[], Graph &graph, double &dist);
    double dijkstra(int start, int end, Graph &graph);
    int minDistance(std::vector<double> dist, std::vector<bool> visited, int numNodes);
    double aStar(int start, int end, Graph &graph);
    std::vector<int> getPath();
    ~SearchAlgorithms(){};
};

#endif //LAB2_SEARCHALGORITHMS_H
