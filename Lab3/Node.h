//
// Created by Andrew on 10/28/2018.
//

#ifndef LAB3_NODE_H
#define LAB3_NODE_H

#include <ostream>

class Node {
private:
    int num;
    double x, y, z;

public:
    Node();
    Node(int, float, float, float);
    Node(const Node& n);
    Node& operator=(const Node& n);

    int getNum() const;
    double getX() const;
    double getY() const;
    double getZ() const;

    double getDist(const Node& rhs);

    bool operator==(int);
    bool operator<(const Node& n);
    bool operator>(const Node& n);
    bool operator==(const Node& n);
    friend std::ostream& operator<<(std::ostream& os, const Node& n);

    ~Node() {};
};

#endif //LAB3_NODE_H
