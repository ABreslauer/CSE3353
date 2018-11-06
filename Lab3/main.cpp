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
    //The looped section of code is for use only for generating data
    /*
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
     */
    int graphSize = 4;      //Overwrite graphSize to be the size of the graph you want to test
    GenerateFiles::generate(graphSize);
    Graph gr;
    gr.loadNodes("../input.txt");
    b->execute(gr);
    b->statsToFile("../outputFiles/bruteForce.csv");
    dP->execute(gr);
    dP->statsToFile("../outputFiles/DP.csv");

    return 0;
}