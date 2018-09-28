//
// Created by Andrew on 9/11/2018.
//

#ifndef LAB2_ALGORITHM_H
#define LAB2_ALGORITHM_H

#include <vector>
#include <tuple>
#include <fstream>
#include "Graph.h"

class Search;
class Algorithm {
public:
    std::string searches[6] = {"DFS Recursive", "DFS Iterative", "BFS Recursive", "BFS Iterative", "Dijkstra", "A*"};
    enum searchTypes {DFS = 0, DFSIterative, BFS, BFSIterative, DIJKSTRA, ASTAR, END};
protected:
    std::vector<std::tuple<Algorithm::searchTypes, double, int, int, double, std::vector<int>, double, double, bool>> stats;
public:
    Algorithm(){};
    virtual ~Algorithm(){};

    virtual void selectAlgo(searchTypes types) = 0;
    virtual void printStats() = 0;
    virtual void normalize() = 0;
    virtual void statsToFile(std::string fileName) = 0;
    virtual void execute(int start, int end, Graph &graph) = 0;

};
#endif //LAB2_ALGORITHM_H
