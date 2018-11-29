//
// Created by Andrew on 11/27/2018.
//
#include "Genetic.h"
#include <random>
Genetic::Genetic() {
    type = 3;
}

void Genetic::execute(Graph &g) {
    initializePop(g);
    for(int i = 0; i < maxGens; i++){
        selectParents(selectionType::BiasedRoulette);
        crossover(parentIndex[0], parentIndex[1], g);
    }
    Solution best = findMin();
    //cout << "Fitness: " << best.getScore() << endl;
    meanFitness += best.getScore();
    iterNum++;
    saveStats(types[type], g.getNodeNum(), attemptNum, best.getScore());
}

void Genetic::initializePop(Graph &g){
    attemptNum = 0;
    pop.clear();
    parentIndex[0] = 0;
    parentIndex[1] = 0;
    for(int i = 0; i < popSize; i++){
        pop.push_back(Solution(g));
    }
}

Solution Genetic::mutate(Solution unlucky, Graph &g) {
    std::uniform_int_distribution<int> distribution(1,unlucky.getPath().size()-1);
    std::default_random_engine generator;
    int index1 = distribution(generator);
    int index2 = distribution(generator);
    unlucky.swapSolution(index1, index2, g);
    return unlucky;
}

void Genetic::selectParents(Genetic::selectionType method) {

    if(method == Genetic::selectionType::BiasedRoulette){
        std::vector<float> adjustedFitness;
        float totalFitness = 0;
        for(int i = 0; i < pop.size(); i++){
            totalFitness += pop[i].getScore();
        }
        for(int i = 0; i < pop.size(); i++){
            adjustedFitness.push_back(pop[i].getScore()/totalFitness);
        }
        double r1 = rand();
        double r2 = rand();
        float CDF = 0;
        for(int i = 0; i < adjustedFitness.size(); i++){
            CDF += adjustedFitness[i];
            if(r1 < CDF && parentIndex[0] == 0){
                parentIndex[0] = i;
            } else if(r2 < CDF && parentIndex[1] ==1){
                parentIndex[1] = i;
            }
        }
    }
    else if(method == Genetic::selectionType::Elitism){
        int bestIndex = 0, secondBestIndex = 0;
        float bestFitness = 0;
        for(int i = 0; i < pop.size(); i++){
            if(pop[i].getScore() > bestFitness){
                secondBestIndex = bestIndex;
                bestIndex = i;
            }
        }
        parentIndex[0] = bestIndex;
        parentIndex[1] = secondBestIndex;
    }
    else if(method == Genetic::selectionType::Random){
        std::uniform_int_distribution<int> distribution(0,popSize - 1);
        std::default_random_engine generator;
        parentIndex[0] = distribution(generator);
        parentIndex[1] = distribution(generator);
    }
}
void Genetic::crossover(int momIndex, int dadIndex, Graph& g) {

    std::vector<int> child1Path, child2Path;
    Solution child1(g), child2(g);
    std::vector<int> parent1 = pop[momIndex].getPath();
    std::vector<int> parent2 = pop[dadIndex].getPath();
    std::uniform_int_distribution<int> distribution(1,child1.getPath().size()-1);
    std::default_random_engine generator;
    int cutoff = distribution(generator);
    for(int i = 0; i < parent1.size(); i++){
        attemptNum++;
        if(i < cutoff){
            child1Path.push_back(parent1[i]);
            child2Path.push_back(parent2[i]);
        } else{
            child1Path.push_back(parent2[i]);
            child2Path.push_back(parent1[i]);
        }
    }
    int mutation = rand();
    if(mutation < mutationRate){
        child1 = mutate(child1,g);
    }
    child1.setPath(child1Path);
    child2.setPath(child2Path);
    if(child1.isValid()){
        pop.push_back(child1);
        pop.erase(pop.begin() + momIndex);
    }
    if(child2.isValid()){
        pop.push_back(child1);
        pop.erase(pop.begin() + dadIndex);
    }
}

Solution Genetic::findMin() {
    float min = 1000;
    int minIndex = 0;
    for(int i = 0; i < pop.size(); i++){
        if(pop[i].getScore() < min){
            min = pop[i].getScore();
            minIndex = i;
        }
    }
    return pop[minIndex];
}

float Genetic::getMean() {
    return meanFitness/iterNum;
}