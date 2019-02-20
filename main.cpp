#include "tree.h"
#include<fstream>
#include<string>

using namespace std;

int main(int argc, char** argv){
  if (argc == 1){
    cout << "Not enough arguments, requires filename.\n";
    return -1;
  }
  else if (argc > 2){
    cout << "Too many arguments, only need filename.\n";
    return -1;
  }
  int currVal;
  node* currNode;
  tree myTree;
  ifstream data;
  data.open(argv[1]);
  if (data.is_open()){
    while(data >> currVal) {
      currNode = myTree.getRoot();
      myTree.insertVal(currVal, currNode);
    }
    data.close();
  }
  else {
    cout << "Could not open " << argv[1];
    return -1;
  }
  myTree.printTree(currNode);
  cout << endl;
  return 0;
}
