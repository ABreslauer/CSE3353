#include <iostream>
#include <cstring>
#include <ctime>
#include "Graph.h"
#include "Algorithm.h"
#include "SearchAlgorithms.h"

int main(int argc, char** argv) {
    srand(time(NULL));
    int numNodes = 16;
    Graph g(numNodes);

    g.loadNodes("../graphInput/graph.txt");
    g.loadPositions("../graphInput/positions.txt");
    g.loadWeights("../graphInput/weights.txt");

    Graph m(numNodes);
    m.loadNodesMatrix("../graphInput/graph.txt");
    m.loadPositions("../graphInput/positions.txt");
    m.loadWeights("../graphInput/weights.txt");

    Algorithm *algorithm = new Search();

    //Used for testing of file inputs, runs each algorithm 100 times with randomized inputs, as well as source->dest and dest->source on both Adjacency Lists and Adjacency Matrices
    if (argc==1) {
        for (int types = 0; types < Algorithm::END; types++) {
            algorithm->selectAlgo(static_cast<Algorithm::searchTypes>(types));
            for (int i = 0; i < 100; i++) {
                int start = rand() % 16 + 1;
                int end = rand() % 16 + 1;
                algorithm->execute(start, end, g);
                algorithm->execute(start, end, m);
            }
        }
        algorithm->statsToFile("../output/output.csv");
        algorithm->normalize();
        algorithm->statsToFile("../output/normalizedOutput.csv");
    }

    else if (argc==3) {
        int start = atoi(argv[1]);
        int end = atoi(argv[2]);
        for (int i = 0; i < Algorithm::END; i++) {
            algorithm->selectAlgo(static_cast<Algorithm::searchTypes>(i));
            algorithm->execute(start, end, g);
            algorithm->execute(start, end, m);
        }
        algorithm->printStats();
    }

    else
        std::cout << "There are not a valid number of command line arguments." << std::endl;
    delete algorithm;
    return 0;
}
