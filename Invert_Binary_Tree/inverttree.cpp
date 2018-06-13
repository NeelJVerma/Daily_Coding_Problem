/*
Invert a binary tree.

For example, given the following tree:

    a
   / \
  b   c
 / \  /
d   e f
should become:

  a
 / \
 c  b
 \  / \
  f e  d
*/

#include <iostream>
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

void Print(Node* root) {
  if (root) {
    Print(root->left);
    cout << root->data << endl;
    Print(root->right);
  }
}

Node* Invert(Node* root) {
  if (!root) {
    return NULL;
  }

  root->left = Invert(root->left);
  root->right = Invert(root->right);

  Node* temp = root->left;
  root->left = root->right;
  root->right = temp;

  return root;
}

int main() {
  Node* root = AddNode(1);
  root->left = AddNode(2);
  root->right = AddNode(3);
  root->left->left = AddNode(4);
  root->left->right = AddNode(5);
  root->right->left = AddNode(6);

  Print(root);
  cout << endl;

  Node* root_2 = Invert(root);
  Print(root_2);

  return 0;
}