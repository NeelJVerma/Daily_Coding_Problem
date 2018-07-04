/*
Given a node in a binary tree, return the next bigger element, also known as the inorder successor.

For example, the inorder successor of 22 is 30.

   10
  /  \
 5    30
     /  \
   22    35
You can assume each node has a parent pointer.
*/

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node* parent;
};

Node* AddNode(int data) {
  Node* return_node = new Node;
  return_node->data = data;
  return_node->left = return_node->right = NULL;

  return return_node;
}

Node* MinInRight(Node* node) {
  Node* current = node->right;

  while (current->left) {
    current = current->left;
  }

  return current;
}

Node* InorderSuccessor(Node* node) {
  if (node->right) {
    return MinInRight(node);
  }

  Node* parent = node->parent;

  while (parent && node == parent->right) {
    node = parent;
    parent = parent->parent;
  }

  return parent;
}

int main() {
  Node* root = AddNode(10);
  root->parent = NULL;
  root->left = AddNode(5);
  root->left->parent = root;
  root->right = AddNode(30);
  root->right->parent = root;
  root->right->left = AddNode(22);
  root->right->left->parent = root->right;
  root->right->right = AddNode(35);
  root->right->right->parent = root->right;

  Node* successor_1 = InorderSuccessor(root->right->left);
  cout << (successor_1->data == 30 ? 1 : 0) << endl;

  Node* successor_2 = InorderSuccessor(root->left);
  cout << (successor_2->data == 10 ? 1 : 0) << endl;

  Node* successor_3 = InorderSuccessor(root);
  cout << (successor_3->data == 22 ? 1 : 0) << endl;

  return 0;
}