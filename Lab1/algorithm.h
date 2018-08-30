//
// Created by Andrew on 8/29/2018.
//

#ifndef LAB1_ALGORITHM_H
#define LAB1_ALGORITHM_H

#include <string>
#include <vector>
#include <tuple>

class algorithm {
protected:
    int selectedAlgorithm;
    std::vector<int> nums;
    std::vector<std::tuple<double, std::string, int>> stats;
    void loadArray(std::vector<int> nums);
public:
    algorithm();
    enum sortingAlgorithms {Bubble, Merge, Insertion};
    void loadFromFile(std::string inputFile);
    virtual void execute();
    void select(sortingAlgorithms a);
    void saveToFile(std::string outputFile);
    virtual void displayResult();
    void printStats();
    //virtual void configure();  For use in the future
    ~algorithm() {}

};

#endif //LAB1_ALGORITHM_H
