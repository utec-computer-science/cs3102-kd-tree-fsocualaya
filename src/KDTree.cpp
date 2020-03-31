//
// Created by notpyxl on 25/03/20.
//

#include <iostream>
#include <queue>
#include "../include/Node.h"

template <typename T>
class KDTree{
    Node<T>* root = nullptr;
    int nodes = 0;
    int k;

    void print(Node<T>* node);
    Node<T>* find(Point<T>, Node<T>* parent);

public:
    KDTree(int k);
    void insert(Point<T> point);
    void findKNN(Point<T>, int k);
    Node<T>* find(Point<T>);
    void print();
};

template<typename T>
KDTree<T>::KDTree(int k){
    this->k = k;
};

template<typename T>
void KDTree<T>::print(Node<T> *node) {
    for(auto&i:node->data)
        std::cout<<i<<", ";
    std::cout<<'\n';
    if(node->left)
        print(node->left);
    if(node->right)
        print(node->right);
}

template <typename T>
void KDTree<T>::print(){
    print(root);
}

template<typename T>
Node<T> *KDTree<T>::find(Point<T> point) {
    if(root){
        return find(point, root);
    }
    return nullptr;
}

template<typename T>
Node<T> *KDTree<T>::find(Point<T> point, Node<T> *parent) {
    if(point[parent->axis] >= parent->data[parent->axis]){
        if(parent->right)
            return find(point, parent->right);
        else {
            return parent;
        }
    } else {
        if(parent->left)
            return find(point, parent->left);
        else{
            return parent;
        }
    }
}

template<typename T>
void KDTree<T>::insert(Point<T> point) {
    Node<T>* parent = find(point);
    Node<T>* node = new Node<T>(this->k, point);

    if(parent){
        if(point[parent->axis] >= parent->data[parent->axis]){
            parent->right = node;
        } else {
            parent->left = node;
        }
        node->axis = (parent->axis+1)%parent->k;
        nodes++;
    } else{
        root = node;
    }
}

template<typename T>
void KDTree<T>::findKNN(Point<T> point, int knn) {
    // TODO
}