//
// Created by Andrew on 9/11/2018.
//

#include "Search.h"
#include "SearchAlgorithms.h"

void Search::selectAlgo(Algorithm::searchTypes types) {
    selectedAlgorithm = types;
}

void Search::printStats() {
    std::cout << "Search Type,Time,Start,End,Number of Nodes,Path,Distance\n";
    for(int i = 0; i < stats.size(); i++){
        std::cout << searches[std::get<0>(stats[i])] << "," << std::get<1>(stats[i]) << "," << std::get<2>(stats[i]) <<
                  "," << std::get<3>(stats[i]) << "," << std::get<4>(stats[i]) << ",";
        for(int j = 0; j < std::get<5>(stats[i]).size() - 1; j++){
            std::cout << std::get<5>(stats[i])[j] << "->";
        }
        std::cout << std::get<5>(stats[i])[std::get<5>(stats[i]).size() - 1] << ",";
        std::cout << std::get<6>(stats[i]) << "," << std::get<7>(stats[i]) << ",";
        if(std::get<8>(stats[i]))
            std::cout << "Matrix\n";
        else
            std::cout << "Adjacency List\n";
    }
}

void Search::statsToFile(std::string fileName) {
    std::ofstream out;
    out.open(fileName);
    if(out.is_open()){
        out << "Search Type,Time,Start,End,Number of Nodes,Path,Distance,Total Nodes Visited\n";
        for(int i = 0; i < stats.size(); i++){
            out << searches[std::get<0>(stats[i])] << "," << std::get<1>(stats[i]) << "," << std::get<2>(stats[i]) <<
                "," << std::get<3>(stats[i]) << "," << std::get<4>(stats[i]) << ",";
            for(int j = 0; j < std::get<5>(stats[i]).size() - 1; j++){
                out << std::get<5>(stats[i])[j] << "->";
            }
            out << std::get<5>(stats[i])[std::get<5>(stats[i]).size() - 1] << ",";
            out << std::get<6>(stats[i]) << "," << std::get<7>(stats[i]) << ",";
            if(std::get<8>(stats[i]))
                out << "Matrix\n";
            else
                out << "Adjacency List\n";
        }
    }
}

void Search::execute(int start, int end, Graph &graph) {
    if(selectedAlgorithm == -1 || selectedAlgorithm == Algorithm::END){
        std::cout << "Select a valid algorithm" << std::endl;
        return;
    }
    SearchAlgorithms s;
    s.selectAlgo(selectedAlgorithm);
    s.execute(this, graph, start, end);
    s.execute(this, graph, end, start);
}

void Search::normalize() {
    double timeMax = 0;
    double numNodesMax = 0;
    double distMax = 0;
    double maxVisited = 0;
    for(int i = 0; i < stats.size(); i++){
        if(std::get<1>(stats[i]) > timeMax)
            timeMax = std::get<1>(stats[i]);
        if(std::get<4>(stats[i]) > numNodesMax)
            numNodesMax = std::get<4>(stats[i]);
        if(std::get<6>(stats[i]) > distMax)
            distMax = std::get<6>(stats[i]);
        if(std::get<7>(stats[i]) > maxVisited)
            maxVisited = std::get<7>(stats[i]);
    }
    for(int i = 0; i < stats.size(); i++){
        if(timeMax != 0)
            std::get<1>(stats[i]) = std::get<1>(stats[i])/timeMax;
        std::get<4>(stats[i]) = std::get<4>(stats[i])/numNodesMax;
        std::get<6>(stats[i]) = std::get<6>(stats[i])/distMax;
        std::get<7>(stats[i]) = std::get<7>(stats[i])/maxVisited;
    }
}

void Search::saveStats(Algorithm::searchTypes type, double time, int start, int end, int numNodes, std::vector<int> finalPath, double distance, double num, bool isMatrix) {
    stat = {type, time, start, end, numNodes, finalPath, distance, num, isMatrix};
    stats.push_back(stat);
}