//
// Created by Andrew on 8/29/2018.
//

#ifndef LAB1_BUBBLESORT_H
#define LAB1_BUBBLESORT_H

#include "sort.h"

class bubbleSort : public sort {
    std::string type = "Bubble";
public:
    bubbleSort();
    void execute() override;
    ~bubbleSort() {}
};

#endif //LAB1_BUBBLESORT_H
