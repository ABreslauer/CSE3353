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
    vector<string> searchAlgorithms = {"Bubble", "Merge", "Insertion"};
    vector<string> fileTypes = {"TwentyPercent", "Random", "ReverseOrder", "ThirtyPercent"};
    vector<int> fileSizes = {10, 1000, 10000, 100000};
    //fileTypes[d] + "Output" + toString(fileSizes[j]);  - input file string for loop


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

    /*
    algorithm test;
    test.select(algorithm::Merge);
    test.loadFromFile("ThirtyPercent100000");
    test.execute();
    test.printStats();
    test.saveToFile("ThirtyPercentOutput100000");
    */

    algorithm a;
    for (int i = 0; i < 3; i++) {  //Sort by all types of search algorithms (Bubble, Insertion, Merge)

        if (i == 0) {
            a.select(algorithm::Bubble);
        } else if (i == 1) {
            a.select(algorithm::Merge);
        } else if (i == 2) {
            a.select(algorithm::Insertion);
        } else {
            cout << "There is not an algorithm past this point." << endl;
        }

        for (int j = 0; j < fileTypes.size(); j++) {         //Sort by all types of file randomization types
            for (int k = 0; k < fileSizes.size(); k++) {
                a.loadFromFile(fileTypes[j] + to_string(fileSizes[k]));
                a.execute();
                a.saveToFile(searchAlgorithms[i] + fileTypes[j] + "Output" + to_string(
                        fileSizes[k]));  //Output files are organized by algo type, randomization type, "output", and # of values
            }
        }
        a.printStats();
    }
}