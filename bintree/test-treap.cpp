#include <iostream>
//#include "bst.h"
#include "treap.h"

int main() {
  Treap<TreapNode1<int>,int> treap;
  BinarySearchTree<BSTNode1<int>,int> bstree;
  
  srand(time(NULL)); // inicializar seed
  
  for (int i = 0; i < 10; i++) {
    treap.add(i);
    bstree.add(i);

    std::cout << "Altura treap " << treap.height() << std::endl;
    std::cout << "Altura bst " << bstree.height() << std::endl;
  }

  return 0;
}
