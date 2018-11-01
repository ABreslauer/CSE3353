//
// Created by Andrew on 10/29/2018.
//

#ifndef LAB3_DYNAMICPROGRAMMING_H
#define LAB3_DYNAMICPROGRAMMING_H

#include "Node.h"
#include <cfloat>
#include <vector>

class DynamicProgramming {
private:
    std::vector<Node> nodeVec;
    double shortestPathLength;
    std::vector<Node> shortestPathNodes;
    long totalPermutations {};
    std::vector<std::vector<double>> nodeMatrix;
public:
    DynamicProgramming() = default;
    explicit DynamicProgramming(const std::string& inFile);

    void read(const std::string& inFile);
    void formMatrix();
    void wtfIsGoingOn();
    ~DynamicProgramming() = default;
};
#endif //LAB3_DYNAMICPROGRAMMING_H
