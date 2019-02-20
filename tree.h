#include<iostream>
#include "node.h"

class tree {
  friend class node;
public:
  tree();
  void insertVal(int val, node* currNode);
  void printTree(node* currNode);
  node* getRoot();
private:
  node* root;
};
