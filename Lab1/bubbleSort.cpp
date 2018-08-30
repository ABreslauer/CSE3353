//
// Created by Andrew on 8/29/2018.
//

#include "bubbleSort.h"
#include <iostream>

bubbleSort::bubbleSort() {}

void bubbleSort::execute() {
    bool isSwapped = true;
    auto t1 = std::chrono::high_resolution_clock::now();
    while(isSwapped) {
        isSwapped = false;
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] > nums[i+1]) {
                nums[i] += nums[i+1];
                nums[i+1] = nums[i] - nums[i+1];
                nums[i] -= nums[i+1];
                isSwapped = true;
            }
        }
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    double time = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();
    saveStats(time, type);
}