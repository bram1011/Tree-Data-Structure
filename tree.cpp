#include "tree.h"

using namespace std;

tree::tree(){
  root = NULL;
}

node* tree::getRoot(){
  return root;
}

void tree::insertVal(int val, node* currNode){
  if (currNode == NULL){
    currNode = new node(val);
    if (root == NULL){
      root = currNode;
    }
  }

  else {
    if(currNode->rightVal == NULLVAL){
      if (val > currNode->leftVal){
        currNode->rightVal = val;
      }
      else {
        currNode->rightVal = currNode->leftVal;
        currNode->leftVal = val;
      }
    }
    else if (val <= currNode->leftVal){
      if (currNode->leftChild == NULL){
        currNode->leftChild = new node(val);
      }
      else {
        currNode = currNode->leftChild;
        insertVal(val, currNode);
      }
    }
    else if (val > currNode->leftVal && val <= currNode->rightVal){
      if (currNode->eqChild == NULL){
        currNode->eqChild = new node(val);
      }
      else {
        currNode = currNode->eqChild;
        insertVal(val, currNode);
      }
    }
    else if (val > currNode->rightVal){
      if (currNode->rightChild == NULL){
        currNode->rightChild = new node(val);
      }
      else{
        currNode = currNode->rightChild;
        insertVal(val, currNode);
      }
    }
  }
}

void tree::printTree(node* currNode){
  //empty tree or end of recursion
  if (currNode == NULL){
    cout << endl;
    return;
  }

  //current node has a left child
  if(currNode->leftChild != NULL){
    cout << "(";
    printTree(currNode->leftChild);
    cout << ") ";
  }


  //print left value
  if (currNode->rightVal == NULLVAL){
    cout <<  currNode->leftVal;
  }
  else {
    cout << currNode->leftVal << " ";
  }

  //current node has eq child
  if (currNode->eqChild != NULL){
    cout << "(";
    printTree(currNode->eqChild);
    cout << ") ";
  }

  //print right value
  if (currNode->rightVal != NULLVAL){
    cout << currNode->rightVal;
  }

  //current node has right child
  if (currNode->rightChild != NULL){
    cout << " (";
    printTree(currNode->rightChild);
    cout << ") ";
  }
}
