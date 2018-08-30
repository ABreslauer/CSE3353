//
// Created by Andrew on 8/29/2018.
//

#include "algorithm.h"
#include "bubbleSort.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include <iostream>
#include <tuple>
#include <fstream>

algorithm::algorithm() {}

void algorithm::loadFromFile(std::string inputFile) {
    nums.clear();
    int num;
    std::ifstream inFile("../inputFiles/" + inputFile + ".txt");
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            inFile >> num;
            nums.push_back(num);
        }
    }
    else {
        std::cout << "File " << inputFile << " was unable to be opened." << std::endl;
    }
    inFile.close();
}

void algorithm::printStats() {
    for (int i = 0; i < stats.size(); i++) {
        std::cout << "Sorting Algorithm: " << std::get<1>(stats[i]) << std::endl;
        std::cout << "# of Values: " << std::get<2>(stats[i]) << std::endl;
        std::cout << "Time: " << std::get<0>(stats[i]) << " microseconds" << std::endl;
    }
}

void algorithm::saveToFile(std::string outputFile) {
    std::ofstream outFile("../outputFiles/" + outputFile + ".txt");
    if (outFile.is_open()) {
        for (int i = 0; i < nums.size(); i++) {
            outFile << nums[i] << std::endl;
        }
    }
    else {
        std::cout << "File " << outputFile << " was unable to be opened." << std::endl;
    }
    outFile.close();
}

void algorithm::select(algorithm::sortingAlgorithms a) {
    std::cout << "selected algorithm number = " << a << std::endl;
    selectedAlgorithm = a;
}

void algorithm::execute() {
    if (selectedAlgorithm == 0) {
        bubbleSort bubble;
        bubble.loadArray(nums);
        bubble.execute();
        nums = bubble.getNums();
        stats.push_back(bubble.getStats());
    }
    else if (selectedAlgorithm == 1) {
        mergeSort merge;
        merge.loadArray(nums);
        merge.execute();
        nums = merge.getNums();
        stats.push_back(merge.getStats());
    }
    else if (selectedAlgorithm == 2) {
        insertionSort insertion;
        insertion.loadArray(nums);
        insertion.execute();
        nums = insertion.getNums();
        stats.push_back(insertion.getStats());
    }
    else {
        std::cout << "There is no other algorithm available here." << std::endl;
    }
}

void algorithm::loadArray(std::vector<int> nums) {
    this->nums = nums;
}

void algorithm::displayResult() {
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << std::endl;
    }
}