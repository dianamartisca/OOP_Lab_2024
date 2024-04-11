#include "Tree.h"
#include <iostream>

int main()
{
    Tree<int> copac(20);
    copac.add_node(nullptr, 4);
    copac.add_node(copac.root, 3);
    copac.add_node(copac.root, 2);
    copac.add_node(copac.root, 1);
    copac.printChildren(copac.root);

    copac.sort(copac.root, compara);
    std::cout << copac.root->value << ' ';
    copac.printChildren(copac.root);

    Node<int>* n = &copac.get_node(copac.root, 2);
    copac.delete_node(n);
    std::cout << copac.root->value << ' ';
    copac.printChildren(copac.root);

    n = &copac.find(copac.root, 3, compara);
    copac.insert(n, 0, 5);
    copac.printChildren(n);

    std::cout<<copac.count(nullptr);
}
