//
// Created by Andrew on 10/28/2018.
//
#include "GenerateFiles.h"
#include <random>
#include <ctime>

void GenerateFiles::generate(int nodeNum){
    srand(time(NULL));
    std::ofstream outFile;
    outFile.open("../input.txt");
    for (int i = 1; i <= nodeNum; i++) {
        outFile << i << ", " << randDouble(0, 20) << ", " << randDouble(0, 20) << ", " << randDouble(0, 20) << "\n";
    }
    outFile.close();
}

double GenerateFiles::randDouble(int min, int max) {
    return static_cast<double>(rand()) / (static_cast<double> (RAND_MAX/max)) + min;
}