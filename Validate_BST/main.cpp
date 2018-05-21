/*
Determine whether a tree is a valid binary search tree.

A binary search tree is a tree with two children, left and right, and satisfies
the constraint that the key in the left child must be less than or equal to the
root and the key in the right child must be greater than or equal to the root.
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

bool IsBST(Node* root) {
  static Node* previous_node = NULL;

  if (root) {
    if (!IsBST(root->left)) {
      return false;
    }

    if (previous_node && root->data < previous_node->data) {
      return false;
    }

    previous_node = root;

    return IsBST(root->right);
  }

  return true;
}

void ValidateCases() {
  Node* root_one = AddNode(2);
  root_one->left = AddNode(2);
  root_one->right = AddNode(3);
  root_one->left->left = AddNode(1);
  root_one->right->left = AddNode(2);

  cout << IsBST(root_one) << endl;

  Node* root_two = AddNode(3);
  root_two->right = AddNode(2);
  root_two->left = AddNode(1);

  cout << IsBST(root_two) << endl;

  Node* root_three = AddNode(3);

  cout << IsBST(root_three) << endl;
}

int main() {
  ValidateCases();

  return 0;
}