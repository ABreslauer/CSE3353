#include <iostream>
#include <vector>
#include "BruteForce.h"
#include "GenerateFiles.h"
#include "DynamicProgramming.h"

using namespace std;

int main() {

    //GenerateFiles g("../Input_Files/test.txt", 4);

    /*
    BruteForce b("../Input_Files/test.txt");
    b.doTSP();
    std::cout << "Total Permutations: " << b.getTotalPermutations() << endl;
    cout << "Path Length: " << b.getShortestPathLength() << endl;
    vector<Node> pathNodes = b.getShortestPathNodes();
    for (int i = 0; i < pathNodes.size(); i++) {
        if (i == pathNodes.size() - 1) {
            cout << pathNodes[i].getNum() << endl;
        } else {
            cout << pathNodes[i].getNum() << ", ";
        }
    }
    */
    DynamicProgramming d("../Input_Files/test.txt");

    /*
    DynamicProgramming d("../Input_Files/test.txt");
    d.doTSP();
    std::cout << "Total Permutations: " << d.getTotalPermutations() << endl;
    cout << "Path Length: " << d.getShortestPathLength() << endl;
    vector<Node> pathNodes = d.getShortestPathNodes();
    for (int i = 0; i < pathNodes.size(); i++) {
        if (i == pathNodes.size() - 1) {
            cout << pathNodes[i].getNum() << endl;
        } else {
            cout << pathNodes[i].getNum() << ", ";
        }
    }
    */

    std::cout << "Hello, World!" << std::endl;
    return 0;
}