//
// Created by Andrew on 8/29/2018.
//

#ifndef LAB1_INSERTIONSORT_H
#define LAB1_INSERTIONSORT_H

#include "sort.h"

class insertionSort : public sort {
    std::string type = "Insertion";
public:
    insertionSort();
    void execute() override;
    ~insertionSort() {}
};

#endif //LAB1_INSERTIONSORT_H
