//
// Created by Andrew on 11/5/2018.
//

#include "Factory.h"
#include "BruteForce.h"
#include "DynamicProgramming.h"
#include "Tabu.h"
#include "Genetic.h"
#include "TSPInterface.h"

TSPInterface* Factory::getNewAlgo(Factory::TSPMethod method) {
    if(method == TSPMethod::BF) {
        TSPInterface *b = new BruteForce();
        return b;
    }

    else if(method == TSPMethod::DP) {
        TSPInterface* dp = new DynamicProgramming();
        return dp;
    }

    else if(method == TSPMethod::TSPTabu) {
        TSPInterface* t = new Tabu();
        return t;
    }
    else if (method == TSPMethod::TSPGenetic) {
        TSPInterface* g = new Genetic();
        return g;
    }

}