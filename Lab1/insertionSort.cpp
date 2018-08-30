//
// Created by Andrew on 8/29/2018.
//

#include "insertionSort.h"

insertionSort::insertionSort() {}

void insertionSort::execute() {
    auto t1 = std::chrono::high_resolution_clock::now();

    int position, tempVal;
    for (int i = 0; i < nums.size(); i++) {
        position = i;
        while (position>0 && nums[position-1]>nums[position]) {
            tempVal = nums[position];
            nums[position] = nums[position-1];
            nums[position-1] = tempVal;
            position--;
        }
    }

    auto t2 = std::chrono::high_resolution_clock::now();
    double time = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();
    saveStats(time, type);
}