//
// Created by Andrew on 11/5/2018.
//

#ifndef LAB3_FACTORY_H
#define LAB3_FACTORY_H

#include "TSPInterface.h"

class Factory {
public:
    enum TSPMethod {BF, DP};
    TSPInterface* getNewAlgo(Factory::TSPMethod method);
};

#endif //LAB3_FACTORY_H
