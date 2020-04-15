//
// Created by notpyxl on 25/03/20.
//

#include <iostream>
#include <set>
#include "../include/Node.h"

template <typename T>
class KDTree{
    Node<T>* root = nullptr;
    int n_nodes = 0;
    int k{};

    void print(Node<T>* node);
    Node<T>* find(Point<T>, Node<T>* parent);

public:
    explicit KDTree(int k);
    void insert(Point<T>& point);
    Node<T>* searchNN(Point<T>&);
    Node<T>* find(Point<T>);
    int size(){return n_nodes;};
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
    bool isParent = false;
    for (int i = 0; i < point.size(); ++i){
        if (point[i] == parent->data[i])
            isParent = true;
    }
    if(isParent)
        return parent;

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
void KDTree<T>::insert(Point<T>& point) {
    Node<T>* parent = find(point);
    Node<T>* node = new Node<T>(this->k, point);

    if(parent){
        if(point[parent->axis] >= parent->data[parent->axis]){
            parent->right = node;
        } else {
            parent->left = node;
        }
        node->axis = (parent->axis+1)%parent->k;
    } else{
        root = node;
    }
    n_nodes++;
}

template<typename T>
void getNodes(Node<T>* node,  std::set<Node<T>*> &nodes) {
    if(node->left) {
        getNodes(node->left, nodes);
    }
    if(node->right) {
        getNodes(node->right, nodes);
    }
    nodes.insert(node);
}

template<typename T>
Node<T>* KDTree<T>::searchNN(Point<T> & point) {
    auto p_point = new Node<T>(k, point);
    std::set<Node<T>*> nodes;
    getNodes(root, nodes);

    Node<T>* nearestNeighbor = nullptr;
    double nearestDistance = 0;

    for(auto&i:nodes){
        double currentDistance = p_point->calculateDistance(i);
        if(nearestDistance == 0 || currentDistance<nearestDistance){
            nearestNeighbor = i;
            nearestDistance = currentDistance;
        }
    }

    return nearestNeighbor;
}