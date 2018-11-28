//
// Created by Andrew on 11/27/2018.
//

#include "Solution.h"
Solution::Solution(Graph &g) {
    initPath(g);
}
void Solution::initPath(Graph &g) {
    long long seed = std::chrono::system_clock::now().time_since_epoch().count();
    for(int i = 2; i <= g.getNodeNum(); i++)
        path.push_back(i);
    shuffle(path.begin(), path.end(), std::default_random_engine(seed));
    path.push_back(1);
    path.insert(path.begin(), 1);
    updateScore(g);
}

void Solution::updateScore(Graph &g) {
    score = 0;
    for(int i = 0; i < path.size() - 1; i++){
        score += g.getDist(path[i], path[i + 1]);
    }
}

int Solution::getLength() {
    return path.size();
}

float Solution::getScore() {
    return score;
}

std::vector<int> Solution::getPath() {
    return path;
}

void Solution::swapSolution(int i, int j, Graph &g) {
    int temp = path[i];
    path[i] = path[j];
    path[j] = temp;
    updateScore(g);
}

Solution& Solution::operator=(const Solution &rhs) {
    this->path = rhs.path;
    this->score = rhs.score;
    return *this;
}

bool Solution::operator==(const Solution &rhs) {
    return this->path == rhs.path;
}

bool Solution::isValid() {
    if(path[0] != 1 || path[path.size() - 1] != 1)
        return false;
    int count;
    for(int i = 2; i < path.size(); i++){
        count  = 0;
        for(int j = 2; j < path.size(); j++){
            if(path[j] == i)
                count++;
        }
        if(count > 1)
            return false;
    }
    return true;
}

void Solution::setPath(std::vector<int> &newPath) {
    path = newPath;
}