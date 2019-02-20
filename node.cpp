#include "node.h"

node::node(int val){
  leftVal = val;
  rightVal = NULLVAL;
  leftChild = NULL;
  rightChild = NULL;
  eqChild = NULL;
}
