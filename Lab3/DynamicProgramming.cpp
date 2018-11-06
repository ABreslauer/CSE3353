//
// Created by Andrew on 10/31/2018.
//

#include "DynamicProgramming.h"
#include <cmath>
#include <algorithm>

DynamicProgramming::DynamicProgramming() {
    type = 1;
}

void DynamicProgramming::execute(Graph &g) {
    std::vector<int> vec;
    path.clear();
    attemptNum = 0;
    bestPath = 10000;
    for(int i = 2; i <= g.getNodeNum(); i++) {
        vec.push_back(i);
    }
    path.push_back(1);
    bestPath = findPath(1,vec,1,g);
    path.push_back(1);
    this->saveStats(types[this->type], g.getNodeNum(), attemptNum, bestPath);
}

double DynamicProgramming::findPath(int start, std::vector<int> mid, int end, Graph &g) {
    if(mid.empty()){
        attemptNum++;
        return static_cast<float>(g.getDist(start, end));
    } else{
        std::vector<float> sum;
        for(int i = 0; i < mid.size(); i++){
            std::vector<int> temp = mid;
            temp.erase(temp.begin() + i);
            double min = 1000;
            int minIndex = 0;
            for(int j = 2; j <= g.getNodeNum(); j++){
                if(g.getDist(start,j) < min) {
                    min = g.getDist(start,j);
                    minIndex = j;
                }
            }
            if(!(count(path.begin(),path.end(),minIndex)))
                path.push_back(minIndex);
            attemptNum++;
            sum.push_back(static_cast<float>((g.getDist(start, mid[i]) + findPath(mid[i],temp,end,g))));
        }
        float min = 1000;
        for(int i = 0; i < sum.size(); i++){
            if(sum[i] < min) {
                min = sum[i];
            }
        }
        return min;
    }
}