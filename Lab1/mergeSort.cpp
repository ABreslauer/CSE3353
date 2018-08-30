//
// Created by Andrew on 8/24/2018.
//

#include "mergeSort.h"

mergeSort::mergeSort() {}

void mergeSort::execute() {
    //Start timer for merge sort
    auto t1 = std::chrono::high_resolution_clock::now();
    //Merge Sort functional code
    sort(nums, 0, nums.size()-1);
    auto t2 = std::chrono::high_resolution_clock::now();
    double time = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();
    saveStats(time, type);
}

void mergeSort::sort(std::vector<int>& nums, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        sort(nums, low, mid);
        sort(nums, mid+1, high);
        merge(nums, low, high, mid);
    }
}

void mergeSort::merge(std::vector<int>& nums, int low, int high, int mid) {
    int i, j, k;
    std::vector<int> temp;
    i = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (nums[i] < nums[j])
        {
            temp.push_back(nums[i]);
            k++;
            i++;
        }
        else
        {
            temp.push_back(nums[j]);
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(nums[i]);
        k++;
        i++;
    }
    while (j <= high)
    {
        temp.push_back(nums[j]);
        k++;
        j++;
    }
    for (i = low; i <= high; i++)
    {
        nums[i] = temp[i-low];
    }
}