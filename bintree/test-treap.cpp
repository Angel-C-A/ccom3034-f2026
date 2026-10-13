#include "treap.h"

int main() {
  Treap<TreapNode1<int>,int> treap;

  treap.add(5);
  treap.add(3);
  treap.add(6);
  return 0;
}
