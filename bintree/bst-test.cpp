#include <iostream>

#include "bst.h"

int main() {
  BinarySearchTree<BSTNode1<int>, int> bstree;

  bstree.add(3);
  bstree.add(1);
  bstree.add(2);
  bstree.add(6);
  bstree.add(4);
  bstree.add(5);
  std::cout << bstree.root->value << std::endl;
  bstree.remove(bstree.root->left);
  std::cout << bstree.root->left->value << std::endl;
  
  return 0;
}
