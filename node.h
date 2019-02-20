#include<cstddef>

const int NULLVAL = -99999;

class node {
  friend class tree;
public:
  node(int val);
private:
  int leftVal;
  int rightVal;
  node* leftChild;
  node* rightChild;
  node* eqChild;
};
