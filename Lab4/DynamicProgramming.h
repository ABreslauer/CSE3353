//
// Created by Andrew on 10/29/2018.
//

#ifndef LAB3_DYNAMICPROGRAMMING_H
#define LAB3_DYNAMICPROGRAMMING_H

#include "TSPInterface.h"
#include "Graph.h"
#include <vector>

class DynamicProgramming : public TSPInterface {
public:
    DynamicProgramming();
    void execute(Graph& g) override;
    double findPath(int start, std::vector<int> mid, int end, Graph& g);

};

#endif //LAB3_DYNAMICPROGRAMMING_H
