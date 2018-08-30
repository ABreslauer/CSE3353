//
// Created by Andrew on 8/29/2018.
//

#include "generateFiles.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>

generateFiles::generateFiles() = default;

void generateFiles::makeData(generateFiles::dataType d, int dataSize) {
    srand(static_cast<unsigned int>(time(nullptr)));
    data.clear();
    if (d == 0) {
        for (int i = 0; i < dataSize; i++) {
            int num = i % 5 + 1;
            data.push_back(num);
        }
    }
    else if (d == 1) {
        for (int i = 0; i < dataSize; i++) {
            int num = rand() % 10000;       //I limited the random numbers from 0-9999, because RAND_MAX is 32767 and this way there's a max of 4 digits
            data.push_back(num);
        }
    }
    else if (d == 2) {
        for (int i = 0; i < dataSize; i++) {
            int num = dataSize - (i+1);
            data.push_back(num);
        }
    }
    else if (d == 3) {
        for (int i = 0; i < dataSize; i++) {
            int inRange = rand() % 100;
            if (inRange < 30) {
                int num = rand() % 10000;
                data.push_back(num);
            }
            else {
                data.push_back(i);
            }
        }
    }
    saveData(d, dataSize);
}

void generateFiles::saveData(generateFiles::dataType d, int dataSize) {
    std::ofstream outFile;
    std::string fileName = std::string("../inputFiles/") + dataTypes[d] + std::to_string(dataSize) + std::string(".txt");
    outFile.open(fileName);
    for (int i = 0; i < data.size(); i++) {
        if (i == data.size()-1) {
            outFile << data[i];
        }
        else {
            outFile << data[i] << std::endl;
        }
    }
}