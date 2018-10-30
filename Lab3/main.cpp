#include <iostream>
#include <vector>
#include "BruteForce.h"
#include "GenerateFiles.h"

using namespace std;

int main() {
    Node n(0, 1.8, 9.2, 1.1);
    cout << n.getDist(n) << endl;

    GenerateFiles g("../Input_Files/test.txt", 6);


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