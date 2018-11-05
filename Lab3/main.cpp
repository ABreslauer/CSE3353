#include <iostream>
#include <vector>
#include "GenerateFiles.h"
#include "Graph.h"
#include "interfaceInterface.h"
#include "Factory.h"
#include "BruteForce.h"

using namespace std;

int main() {
    Factory makeStuff;
    interfaceInterface* b = makeStuff.getNewAlgo(Factory::TSPMethod::BF);
    interfaceInterface* dP = makeStuff.getNewAlgo(Factory::TSPMethod::DP);
    for (int i = 4; i <= 11; i++) {
        GenerateFiles::generate(i);
        Graph g;
        g.loadNodes("../input.txt");
        b->execute(g);
        b->statsToFile("../outputFiles/bruteForce.csv");
        dP->execute(g);
        dP->statsToFile("../outputFiles/DP.csv");
        cout << i << " nodes graph completed." << endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}