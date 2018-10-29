#include <iostream>
#include <vector>
#include "BruteForce.h"

using namespace std;

int main() {

    BruteForce b("../Input_Files/input.txt");
    b.doTSP();
    std::cout << "Total Permutations: " << b.getTotalPermutations() << endl;
    cout << "Path Length: " << b.getShortestPathLength() << endl;
    vector<Node> pathNodes = b.getShortestPathNodes();
    for (int i = 0; i < pathNodes.size(); i++) {
        if (i == pathNodes.size()-1) {
            cout << pathNodes[i].getNum() << endl;
        }
        else {
            cout << pathNodes[i].getNum() << ", ";
        }
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}