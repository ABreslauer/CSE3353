//
// Created by Andrew on 10/28/2018.
//
#include "Node.h"
#include <cmath>

Node::Node() {
    num, x, y, z = 0;
}

Node::Node(int n, float xVal, float yVal, float zVal) {
    num = n;
    x = xVal;
    y = yVal;
    z = zVal;
}

Node::Node(const Node& n) {
    num = n.getNum();
    x = n.getX();
    y = n.getY();
    z = n.getZ();
}

Node& Node::operator=(const Node& n) {
    num = n.getNum();
    x = n.getX();
    y = n.getY();
    z = n.getZ();
}

int Node::getNum() const {
    return num;
}

double Node::getX() const {
    return x;
}

double Node::getY() const {
    return y;
}

double Node::getZ() const {
    return z;
}

double Node::getDist(const Node& rhs) {
    return std::sqrt(pow((rhs.getX() - x),2) + pow((rhs.getY() - y),2) + pow((rhs.getZ() - z),2));
}

bool Node::operator==(int n) {
    return num==n;
}

bool Node::operator==(const Node& n) {
    return num==n.getNum();
}

bool Node::operator<(const Node& n) {
    return num<n.getNum();
}

bool Node::operator>(const Node& n) {
    return num>n.getNum();
}

std::ostream& operator<<(std::ostream& os, const Node& n) {
    os << n.getNum() << ", " << n.getX() << ", " << n.getY() << ", " << n.getZ() << std::endl;
    return os;
}