//
// Created by Andrew on 8/29/2018.
//

#ifndef LAB1_MERGESORT_H
#define LAB1_MERGESORT_H

#include <cstring>
#include "sort.h"

class mergeSort : public sort {
private:
    std::string type = "Merge";
    void merge(std::vector<int>& nums, int low, int high, int mid);
    void sort(std::vector<int>& nums, int low, int high);
public:
    mergeSort();
    void execute() override;
};

#endif //LAB1_MERGESORT_H
