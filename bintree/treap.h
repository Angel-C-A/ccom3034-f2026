// treap.h - A binary tree that *also* has the heap property.
// Copyright 2026 Humberto Ortiz Zuazaga
// Based on Treap class by Pat Morin
// in https://opendatastructures.org/
// Released under
// https://creativecommons.org/licenses/by/2.5/ca/

#ifndef TREAP_H
#define TREAP_H

#include <stdlib.h>

#include "bst.h"

template<class Node, class T> class Treap;

template<class Node, class T>
  class TreapNode : public BSTNode<Node, T> {
 protected:
  friend class Treap<Node, T>;
  int priority;
};

template<class Node, class T>
  class Treap : public BinarySearchTree<Node,T> {
 protected:
  using BinaryTree<Node>::root;

  // metodos internos
  void bubbleUp(Node *u);
  void trickleDown(Node *u);
  
 public:
  Treap();
  ~Treap();
  bool add(T x);
  bool remove(T x);
};

template<class Node, class T>
Treap<Node,T>::Treap() {}

template<class Node, class T>
Treap<Node,T>::~Treap() {}

template<class Node, class T>
bool Treap<Node,T>::add(T x) {
  Node *u = new Node;
  u->value = x;
  u->priority = rand();
  if (BinarySearchTree<Node,T>::add(u)) {
    bubbleUp(u);
    return true;
  }
  return false;
}

template<class Node, class T>
void Treap<Node,T>::bubbleUp(Node *u) {
  while (u->parent != nullptr && u->parent->priority > u->priority) {
    if (u->parent->right == u) {
      this->rotateLeft(u->parent);
    } else {
      this->rotateRight(u->parent);
    }
    if (u->parent == nullptr) {
      root = u;
    }
  }
}

// probablemente estoy roto, falta mucho

template<class T>
class TreapNode1 : public TreapNode<TreapNode1<T>, T> { };

#endif
