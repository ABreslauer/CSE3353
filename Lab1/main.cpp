#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "algorithm.h"
#include "sort.h"
#include "bubbleSort.h"
#include "generateFiles.h"

using namespace std;

int main(int argc, char* argv[]) {
    /**
     * The different type of algorithms, randomization types, and randomization sizes for the entire project
     */
    vector<string> searchAlgorithms = {"Bubble", "Merge", "Insertion"};
    vector<string> fileTypes = {"TwentyPercent", "Random", "ReverseOrder", "ThirtyPercent"};
    vector<int> fileSizes = {10, 1000, 10000, 100000};\

    /**
     * This is the code used to generate newly randomized files for each size and file type
     */
    /*
    generateFiles g;
    g.makeData(generateFiles::TwentyPercent, 10);
    g.makeData(generateFiles::TwentyPercent, 1000);
    g.makeData(generateFiles::TwentyPercent, 10000);
    g.makeData(generateFiles::TwentyPercent, 100000);

    g.makeData(generateFiles::Random, 10);
    g.makeData(generateFiles::Random, 1000);
    g.makeData(generateFiles::Random, 10000);
    g.makeData(generateFiles::Random, 100000);

    g.makeData(generateFiles::ReverseOrder, 10);
    g.makeData(generateFiles::ReverseOrder, 1000);
    g.makeData(generateFiles::ReverseOrder, 10000);
    g.makeData(generateFiles::ReverseOrder, 100000);

    g.makeData(generateFiles::ThirtyPercent, 10);
    g.makeData(generateFiles::ThirtyPercent, 1000);
    g.makeData(generateFiles::ThirtyPercent, 10000);
    g.makeData(generateFiles::ThirtyPercent, 100000);
    */
    /**
     * This is the test case for if any algorithm wasn't working with any certain filetype, and was not deleted as an
     * example of the in-order steps needed to run each algorithm type
     */
    /*
    algorithm test;
    test.select(algorithm::Bubble);
    test.loadFromFile("ReverseOrder10");
    test.execute();
    test.displayResult();
    test.printStats();
    test.saveToFile("ThirtyPercentOutput100000");
    */

    /**
     * The loop that runs each type of algorithm across all of the files. It is done by loading in a sorting algorithm
     * type, and then running each of the file randomization types across each algorithm at each different file size
     */
    algorithm a;
    for (int i = 0; i < 3; i++) {  //Sort by all types of search algorithms (Bubble, Insertion, Merge)
        a.select(algorithm::sortingAlgorithms(i));
        for (int j = 0; j < fileTypes.size(); j++) {         //Sort by all types of file randomization types
            for (int k = 0; k < fileSizes.size(); k++) {
                a.loadFromFile(fileTypes[j] + to_string(fileSizes[k]));
                a.execute();
                a.saveToFile(searchAlgorithms[i] + fileTypes[j] + "Output" + to_string(fileSizes[k]));
            }
        }
    }
    a.printStats();
}