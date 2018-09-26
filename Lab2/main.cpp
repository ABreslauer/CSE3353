#include <iostream>
#include <cstring>
#include "Graph.h"
#include "Algorithm.h"
#include "SearchAlgorithms.h"

int main(int argc, char** argv) {
    int numNodes = 16;
    Graph g(numNodes);
    Graph matrix(numNodes);

    g.loadNodes("../graphInput/graph.txt");
    g.loadPositions("../graphInput/positions.txt");
    g.loadWeights("../graphInput/weights.txt");

    matrix.loadNodes("../graphInput/graph.txt");
    matrix.loadPositions("../graphInput/positions.txt");
    matrix.loadWeights("../graphInput/weights.txt");

    Algorithm *algorithm = new Search();

    if (argc==1) {
        for (int types = 0; types < Algorithm::END; types++) {
            algorithm->selectAlgo(static_cast<Algorithm::searchTypes>(types));
            for (int i = 0; i < 100; i++) {
                int start = rand() % 16 + 1;
                int end = rand() % 16 + 1;
                algorithm->execute(start, end, g);
                algorithm->execute(start, end, matrix);
            }
        }
        algorithm->statsToFile("../output/output.csv");
        algorithm->normalize();
        algorithm->statsToFile("../output/normalOutput.csv");
    }

    else
        std::cout << "Please enter valid argument types." << std::endl;
    delete algorithm;
    return 0;
}
