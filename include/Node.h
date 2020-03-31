//
// Created by notpyxl on 25/03/20.
//

#ifndef CS3102_KD_TREE_FSOCUALAYA_NODE_H
#define CS3102_KD_TREE_FSOCUALAYA_NODE_H

#include <vector>

template <typename T>
using Point = std::vector<T>;

template <typename T>
struct Node{
    int k;
    Point<T> data;
    Node<T> *left = nullptr, *right = nullptr;
    short axis;

    Node(int k);
    Node(int k, Point<T> point); // Fixed for k = 2
};

template<typename T>
Node<T>::Node(int k) {
    this->k = k;
    data.resize(k);
}

template<typename T>
Node<T>::Node(int k, Point<T> point) {
    this->k = k;
    data.resize(k);
    this->data[0] = point[0];
    this->data[1] = point[1];
}

#endif // CS3102_KD_TREE_FSOCUALAYA_NODE_H