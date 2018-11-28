//
// Created by Andrew on 11/27/2018.
//

#ifndef LAB4_GENETIC_H
#define LAB4_GENETIC_H

#include "TSPInterface.h"

class Genetic : public TSPInterface {
    int popSize = 100;
    std::vector<Solution> pop;
    int parentIndex[2] = {0,0};
    float mutationRate = 0.25;
    int iterNum = 0;
    int maxGens = 3000;
    float meanFitness = 0;
    void initializePop(Graph& g);
    Solution findMin();
public:
    Genetic();
    float getMean();
    enum selectionType {BiasedRoulette, Random, Elitism};
    void execute(Graph& g) override;
    void crossover(int momIndex, int daddyIndex, Graph& g);
    Solution mutate(Solution iSuck, Graph& g);
    void selectParents(selectionType selection);

};

#endif //LAB4_GENETIC_H
