#include "src/KDTree.cpp"

int main() {

    Point<int> p1 = {3, 6};
    auto p2 = {2,7};
    auto p3 = {17,15};
    auto p4 = {6,12};
    auto p5 = {9,1};
    auto p6 = {13,15};
    auto p7 = {10,19};

    //kdTree.print();

    KDTree<int> kdTree(2);
    kdTree.insert(p1);
    kdTree.insert(p2);
    kdTree.insert(p3);
    kdTree.insert(p4);
    kdTree.insert(p5);
    kdTree.insert(p6);
    kdTree.insert(p7);
    kdTree.insert({1,5});

    auto nodes = kdTree.findKNN(p1, 5);

    std::cout<< kdTree.size()<<'\n';

    for(auto&i:nodes){
        std::cout<<i->data[0]<<' '<<i->data[1]<<' '<< i->calculateDistance(kdTree.find({3,6})) << '\n';
    }
    return 0;
}