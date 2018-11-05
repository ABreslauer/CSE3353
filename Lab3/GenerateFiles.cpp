//
// Created by Andrew on 10/28/2018.
//
#include "GenerateFiles.h"
#include <random>
#include <ctime>

GenerateFiles::GenerateFiles(const std::string& output, int nodeNum) {
    std::ofstream outFile;
    outFile.open(output);
    srand(time(NULL));
    int temp {};
    double temp1, temp2, temp3 {};
    if (outFile.is_open()) {
        for (int i = 0; i < nodeNum; i++) {
            if (i != nodeNum-1) {
                temp++;
                temp1 = (double)rand() / (double)1000;
                temp2 = (double)rand() / (double)1000;
                temp3 = (double)rand() / (double)1000;
                outFile << temp << ", " << temp1 << ", " << temp2 << ", " << temp3 << std::endl;
            }
            else {
                temp++;
                temp1 = (double)rand() / (double)1000;
                temp2 = (double)rand() / (double)1000;
                temp3 = (double)rand() / (double)1000;
                outFile << temp << ", " << temp1 << ", " << temp2 << ", " << temp3;
            }

        }
    }
}