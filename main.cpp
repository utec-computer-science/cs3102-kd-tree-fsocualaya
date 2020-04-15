#include "src/KDTree.cpp"

int main() {

    Point<int> p1 = {3, 6};
    Point<int> p2 = {2,7};
    Point<int> p3 = {17,15};
    Point<int> p4 = {6,12};
    Point<int> p5 = {9,1};
    Point<int> p6 = {13,15};
    Point<int> p7 = {10,19};

    //kdTree.print();

    KDTree<int> kdTree(2);
    kdTree.insert(p1);
    kdTree.insert(p2);
    kdTree.insert(p3);
    kdTree.insert(p4);
    kdTree.insert(p5);
    kdTree.insert(p6);
    kdTree.insert(p7);

    Point<int> p8 = {11,8};

    auto nn = kdTree.searchNN(p4);

    std::cout<< kdTree.size()<<'\n';

    std::cout<<nn->data[0]<<','<<nn->data[1]<<'\n';
    return 0;
}