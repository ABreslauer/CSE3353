//
// Created by Andrew on 9/11/2018.
//

#include <chrono>
#include <algorithm>
#include <stack>
#include "SearchAlgorithms.h"

void SearchAlgorithms::execute(Search *search, Graph &graph, int start, int end) {
    auto time1 = std::chrono::system_clock::now();
    double dist = 0;
    switch(selectedAlgorithm){
        case 0:
            dist = DFSSetup(start, end, graph);
            break;
        case 1:
            dist = DFSIterative(start, end, graph);
            break;
        case 2:
            dist = BFSSetup(start, end, graph);
            break;
        case 3:
            dist = BFSIterative(start, end, graph);
            break;
        case 4:
            dist = dijkstra(start, end, graph);
            break;
        case 5:
            dist = aStar(start, end, graph);
            break;
    }
    auto time2 = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = time2 - time1;
    double time = std::chrono::duration_cast<std::chrono::microseconds>(diff).count();
    search->saveStats(selectedAlgorithm, time, start, end, path.size(), path, dist, numNodes, graph.isMatrix());
}

double SearchAlgorithms::DFSSetup(int start, int end, Graph &graph) {
    numNodes = 0;
    path.clear();
    double dist = 0;
    bool *visited = new bool[graph.getSize()];
    for(int i = 0; i < graph.getSize(); i++)
        visited[i] = false;
    DFS(start, end, visited, graph, dist);
    while(path[path.size() - 1] != end)
        path.pop_back();
    return dist;
}

void SearchAlgorithms::DFS(int node, int end, bool *visited, Graph &graph, double &dist) {
    visited[node - 1] = true;
    path.push_back(node);
    numNodes++;

    if(node == end)
        return;
    std::vector<int> newPaths = graph.getPaths(node);
    for(int i = 0; i < newPaths.size(); i++){
        if(!visited[newPaths[i] - 1]) {
            dist += graph.getWeight(node, newPaths[i]);
            DFS(newPaths[i], end, visited, graph, dist);
        }
    }
}

double SearchAlgorithms::DFSIterative(int start, int end, Graph &graph) {
    path.clear();
    numNodes = 0;
    double dist = 0;
    std::vector<bool> visited(graph.getSize(), false);
    std::stack<int> stack;
    int node;
    stack.push(start);
    while(!stack.empty()){
        node = stack.top();
        stack.pop();
        if(!visited[node - 1]){
            visited[node - 1] = true;
            path.push_back(node);
            numNodes++;
        }
        std::vector<int> newPaths = graph.getPaths(node);
        for(int i = 0; i < newPaths.size(); i++){
            if(!visited[newPaths[i] - 1]){
                stack.push(newPaths[i]);
                dist += graph.getWeight(node, newPaths[i]);
            }
        }
    }
    while(path[path.size() - 1] != end)
        path.pop_back();
    return dist;

}

double SearchAlgorithms::BFSSetup(int start, int end, Graph &graph) {
    path.clear();
    double dist = 0;
    numNodes = 0;
    std::queue<int> queue;
    std::vector<bool> visited(graph.getSize(), false);
    visited[start - 1] = true;
    queue.push(start);
    if(start == end) {
        path.push_back(start);
        numNodes++;
    }
    BFS(start, end, queue, visited, graph, dist);
    while(path[path.size() - 1] != end)
        path.pop_back();
    return dist;

}

void SearchAlgorithms::BFS(int node, int end, std::queue<int> &queue, std::vector<bool> discovered, Graph &graph, double &dist) {
    if(node == end)
        return;
    if(queue.empty())
        return;
    int v = queue.front();
    queue.pop();
    path.push_back(v);
    numNodes++;
    std::vector<int> newPaths = graph.getPaths(v);
    for(int i = 0; i < newPaths.size(); i++){
        if(!discovered[newPaths[i] - 1]){
            discovered[newPaths[i]- 1] = true;
            queue.push(newPaths[i]);
            if(graph.isPath(node, newPaths[i]))
                dist += graph.getWeight(node, newPaths[i]);
        }
    }
    BFS(v, end, queue, discovered, graph, dist);
}

double SearchAlgorithms::BFSIterative(int start, int end, Graph &graph){
    path.clear();
    numNodes = 0;
    double dist = 0;
    std::vector<bool> visited(graph.getSize(), false);
    std::queue<int> queue;
    int node;
    queue.push(start);
    while(!queue.empty()){
        node = queue.front();
        queue.pop();
        if(!visited[node - 1]){
            visited[node - 1] = true;
            path.push_back(node);
            numNodes++;
        }
        std::vector<int> newPaths = graph.getPaths(node);
        for(int i = 0; i < newPaths.size(); i++){
            if(!visited[newPaths[i] - 1]){
                queue.push(newPaths[i]);
                dist += graph.getWeight(node, newPaths[i]);
            }
        }
    }
    while(path[path.size() - 1] != end)
        path.pop_back();
    return dist;

}

std::vector<int> SearchAlgorithms::getPath() {
    return path;
}

double SearchAlgorithms::dijkstra(int start, int end, Graph &graph) {
    path.clear();
    numNodes = 0;
    std::vector<double> dist(graph.getSize(), 1000);
    std::vector<bool> visited(graph.getSize(), false);
    dist[start - 1] = 0;
    for(int count = 0; count < graph.getSize() * graph.getSize(); count++){
        int min = minDistance(dist, visited, graph.getSize()) + 1;
        visited[min - 1] = true;
        if(min == end){
            path.push_back(min);
            numNodes++;
            return dist[end - 1];
        }
        std::vector<int> newPaths = graph.getPaths(min);
        for(int i = 0; i < newPaths.size(); i++){
            if(!visited[newPaths[i] - 1] &&
               dist[min - 1] + graph.getWeight(min, newPaths[i]) < dist[newPaths[i] - 1]) {
                if (!(std::find(path.begin(), path.end(), min) != path.end())) {
                    path.push_back(min);
                    numNodes++;
                }
                dist[newPaths[i] - 1] = dist[min - 1] + graph.getWeight(min, newPaths[i]);
                if(min == end){
                    std::cout << dist[end - 1] << std::endl;
                    return dist[end - 1];
                }
            }
        }
    }
    return -1;
}

int SearchAlgorithms::minDistance(std::vector<double> dist, std::vector<bool> visited, int numNodes) {
    double min = 1000;
    int minIndex = -1;
    for(int i = 0; i < numNodes; i++){
        if(!visited[i] && dist[i] <= min){
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

double SearchAlgorithms::aStar(int start, int end, Graph &graph) {
    path.clear();
    numNodes = 0;
    std::vector<double> weight(graph.getSize(), 1000);
    std::vector<bool> visited(graph.getSize(), false);
    weight[start - 1] = 0;
    for(int count = 0; count < graph.getSize() * graph.getSize(); count++){
        int min = minDistance(weight, visited, graph.getSize()) + 1;
        visited[min - 1] = true;
        if(min == end){
            path.push_back(min);
            numNodes++;
            return weight[end - 1];
        }
        std::vector<int> newPaths = graph.getPaths(min);
        for(int i = 0; i < newPaths.size(); i++){
            double dist = graph.getDistance(min, newPaths[i]);
            if(!visited[newPaths[i] - 1] &&
               weight[min - 1] + dist*(1 + graph.getWeight(min, newPaths[i])) < weight[newPaths[i] - 1]) {
                if (!(std::find(path.begin(), path.end(), min) != path.end())) {
                    path.push_back(min);
                    numNodes++;
                }
                weight[newPaths[i] - 1] = weight[min - 1] + dist*(1 + graph.getWeight(min, newPaths[i]));
                if(min == end){
                    std::cout << weight[end - 1] << std::endl;
                    return weight[end - 1];
                }
            }
        }
    }
    return -1;
}