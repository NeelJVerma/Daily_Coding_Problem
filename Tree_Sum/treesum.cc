/*
Given the root of a binary search tree, and a target K, return two nodes in the tree whose sum equals K.

For example, given the following tree and K of 20

    10
   /   \
 5      15
       /  \
     11    15
Return the nodes 5 and 15.
*/

#include <iostream>
#include <unordered_set>
#include <queue>
#include <cstdlib>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

Node* AddNode(int data) {
  Node* return_node = new Node;
  return_node->data = data;
  return_node->left = return_node->right = NULL;

  return return_node;
}

struct ReturnPair {
  int one;
  int two;
  bool found;
};

ReturnPair TreeSum(Node* root, int k) {
  unordered_set<int> complements;
  queue<Node*> q;
  q.push(root);
  ReturnPair rp;
  rp.one = 0;
  rp.two = 0;
  rp.found = false;

  while (q.size()) {
    Node* visited = q.front();
    q.pop();
    int complement = k - visited->data;

    if (complements.find(visited->data) != complements.end()) {
      rp.one = visited->data;
      rp.two = complement;
      rp.found = true;
      return rp;
    }

    complements.insert(complement);

    if (visited->left) {
      q.push(visited->left);
    }

    if (visited->right) {
      q.push(visited->right);
    }
  }

  return rp;
}

int main() {
  Node* root_1 = AddNode(10);
  root_1->left = AddNode(5);
  root_1->right = AddNode(15);
  root_1->right->left = AddNode(11);
  root_1->right->right = AddNode(15);
  ReturnPair rp_1 = TreeSum(root_1, 20);

  if (!rp_1.found) {
    cout << "Sum not found for root_1" << endl;
  } else {
    cout << rp_1.one << ' ' << rp_1.two << endl;
  }

  Node* root_2 = AddNode(15);
  root_2->left = AddNode(5);
  root_2->right = AddNode(16);
  ReturnPair rp_2 = TreeSum(root_2, 16);

  if (!rp_2.found) {
    cout << "Sum not found for root_2" << endl;
  } else {
    cout << rp_2.one << ' ' << rp_2.two << endl;
  }
  
  return 0;
}