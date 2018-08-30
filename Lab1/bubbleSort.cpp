//
// Created by Andrew on 8/29/2018.
//

#include "bubbleSort.h"
bubbleSort::bubbleSort() {}

void bubbleSort::execute() {
    bool isSwapped = true;
    int temp {};
    auto t1 = std::chrono::high_resolution_clock::now();
    while(isSwapped) {
        isSwapped = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums[i+1]) {
                temp = nums[i+1];
                nums[i+1] = nums[i];
                nums[i] = temp;
                isSwapped = true;
            }
        }
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    double time = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();
    saveStats(time, type);
}