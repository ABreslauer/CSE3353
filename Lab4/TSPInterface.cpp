//
// Created by Andrew on 11/5/2018.
//

#include "TSPInterface.h"

void TSPInterface::statsToFile(std::string outFile) {
    std::ofstream output;
    output.open(outFile);
    if(output.is_open()) {
        output << "Type, Number of Nodes, Number of Permutations, Minimum Distance\n";
        for (int i = 0; i < stats.size(); i++) {
            output << stats[i].algoType << "," << stats[i].nodeNum << "," << stats[i].permutationNum << ","
                   << stats[i].dist << "\n";
        }
        output.close();
    }
    else {
        std::cout << "File: " << outFile << " failed to open." << std::endl;
    }
}

void TSPInterface::saveStats(std::string algoType, int nodeNum, int permutationNum, double dist) {
    Stat s;
    s.algoType = algoType;
    s.nodeNum = nodeNum;
    s.permutationNum = permutationNum;
    s.dist = dist;
    stats.push_back(s);
}