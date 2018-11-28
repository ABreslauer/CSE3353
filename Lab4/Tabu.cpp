//
// Created by Andrew on 11/27/2018.
//

#include "Tabu.h"
#include <algorithm>
Tabu::Tabu() {
    type = 2;
}
void Tabu::execute(Graph &g) {
    attemptNum = 0;
    path.clear();
    tabuList.clear();
    Solution best = Solution(g);
    tabuList.push_back(best);
    int numTries = 0;
    while(numTries < iterNum) {
        best = findNeighbor(best, g);
        tabuList.push_back(best);
        if(tabuList.size() > listSize){
            tabuList.erase(tabuList.begin());
        }
        numTries++;
    }
    //best = getMin();
    for (int i = 0; i < best.getPath().size(); i++) {
        std::cout << best.getPath()[i] << " ";
    }
    std::cout << "Fitness: " << best.getScore() << " Number of operations: " << attemptNum << std::endl;
    saveStats(types[type], g.getNodeNum(), attemptNum, best.getScore());

}

void Tabu::setListSize(int num){
    listSize = num;
}
Solution Tabu::findNeighbor(Solution best, Graph &g) {
    Solution newSoln = best;
    for(int i = 1; i < g.getNodeNum(); i++){
        for(int j = 1; j < g.getNodeNum(); j++){
            newSoln.swapSolution(i,j,g);
            attemptNum++;
            if((newSoln.getScore() < best.getScore()) && !contains(newSoln)){
                best = newSoln;
            }
        }
    }
    return best;
}

bool Tabu::contains(Solution s) {
    for(int i = 0; i < tabuList.size(); i++){
        if(s == tabuList[i])
            return true;
    }
    return false;
}

Solution Tabu::getMin(){
    float min = 1000;
    int minIndex = 0;
    for(int i = 0; i < tabuList.size(); i++){
        if(tabuList[i].getScore() < min){
            minIndex = i;
        }
    }
    return tabuList[minIndex];
}