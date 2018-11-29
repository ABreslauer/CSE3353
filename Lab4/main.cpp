#include <iostream>
#include <vector>
#include "GenerateFiles.h"
#include "Graph.h"
#include "interfaceInterface.h"
#include "Factory.h"

using namespace std;

int main() {
    Factory makeStuff;
    interfaceInterface* b = makeStuff.getNewAlgo(Factory::TSPMethod::BF);
    interfaceInterface* d = makeStuff.getNewAlgo(Factory::TSPMethod::DP);
    interfaceInterface* t = makeStuff.getNewAlgo(Factory::TSPMethod::TSPTabu);
    interfaceInterface* g = makeStuff.getNewAlgo(Factory::TSPMethod::TSPGenetic);

    for (int i = 4; i <= 15; i++) {
        GenerateFiles::generate(i);
        cout << "i = " << i << endl;
        Graph graph;
        graph.loadNodes("../input.txt");
        if (i <= 10) {
            b->execute(graph);
            d->execute(graph);
        }
        t->execute(graph);
        g->execute(graph);
    }
    b->statsToFile("../outputFiles/bruteForce.csv");
    d->statsToFile("../outputFiles/DP.csv");
    t->statsToFile("../outputFiles/tabuOutput.csv");
    g->statsToFile("../outputFiles/geneticOutput.csv");
    return 0;
}