//
// Created by Andrew on 8/29/2018.
//

#ifndef LAB1_GENERATEFILES_H
#define LAB1_GENERATEFILES_H

#include <vector>

class generateFiles {
public:
    enum dataType {TwentyPercent, Random, ReverseOrder, ThirtyPercent};
private:
    void saveData(dataType d, int dataSize);
    std::vector<int> data;
public:
    generateFiles();
    void makeData(dataType d, int dataSize);
    const char* dataTypes[4] = {"TwentyPercent", "Random", "ReverseOrder", "ThirtyPercent"};
};

#endif //LAB1_GENERATEFILES_H
