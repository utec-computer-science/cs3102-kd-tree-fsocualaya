//
// Created by notpyxl on 25/03/20.
//

#ifndef CS3102_KD_TREE_FSOCUALAYA_NODE_H
#define CS3102_KD_TREE_FSOCUALAYA_NODE_H

#include <vector>
#include <cmath>

template <typename T>
using Point = std::vector<T>;

template <typename T>
struct Node{
    int k;
    Point<T> data;
    Node<T> *left = nullptr, *right = nullptr;
    short axis;

    Node(int k);
    Node(int k, Point<T>& point); // Fixed for k = 2
    double calculateDistance(Node<T>* node);
};

template<typename T>
Node<T>::Node(int k) {
    this->k = k;
    data.resize(k);
}

template<typename T>
Node<T>::Node(int k, Point<T>& point) {
    this->k = k;
    data.resize(k);
    this->data = point;
}

template<typename T>
double Node<T>::calculateDistance(Node<T>* node) {
    double squareSum = 0;
    for(int i=0;i< this->k;++i){
        squareSum += pow(this->data[i] - node->data[i], 2);
    }
    return sqrt(squareSum);
}

#endif // CS3102_KD_TREE_FSOCUALAYA_NODE_H