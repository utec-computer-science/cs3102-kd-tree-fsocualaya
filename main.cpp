#include "src/KDTree.cpp"

int main() {

    /*
    Node<int> node(2);
    node.data[0] = 3; node.data[1] = 6;

    Node<int> node2(2);
    node2.data[0] = 2; node2.data[1] = 7;

    Node<int> node3(2);
    node3.data[0] = 17; node3.data[1] = 15;

    Node<int> node4(2);
    node4.data[0] = 6; node4.data[1] = 12;

    Node<int> node5(2);
    node5.data[0] = 9; node5.data[1] = 1;

    Node<int> node6(2);
    node6.data[0] = 13; node6.data[1] = 15;
    */
    //Node<int> node7(2);
    //node7.data[0] = 10; node7.data[1] = 19;


    KDTree<int> kdTree(2);
    auto p1 = {3,6};
    auto p2 = {2,7};
    auto p3 = {17,15};
    auto p4 = {6,12};
    auto p5 = {9,1};
    auto p6 = {13,15};
    auto p7 = {10,19};

    /*
    kdTree.insert(&node);
    kdTree.insert(&node2);
    kdTree.insert(&node3);
    kdTree.insert(&node4);
    kdTree.insert(&node5);
    kdTree.insert(&node6);
    kdTree.insert(&node7);*/

    //kdTree.print();

    kdTree.insert(p1);
    kdTree.insert(p2);
    kdTree.insert(p3);
    kdTree.insert(p4);
    kdTree.insert(p5);
    kdTree.insert(p6);
    kdTree.insert(p7);



    return 0;
}