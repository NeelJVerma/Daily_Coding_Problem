/*
Given the root to a binary search tree, find the second largest node in the tree.
*/

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

Node* NewNode(int data) {
  Node* node = new Node;
  node->data = data;
  node->left = node->right = NULL;

  return node;
}

Node* Insert(Node* root, int data) {
  if (!root) {
    return NewNode(data);
  }

  if (data < root->data) {
    root->left = Insert(root->left, data);
  } else {
    root->right = Insert(root->right, data);
  }

  return root;
}

void SecondLargestUtil(Node* root, int& counter, Node** ret) {
  if (!root || counter >= 2) {
    return;
  }

  SecondLargestUtil(root->right, counter, ret);
  counter++;

  if (counter == 2) {
    *ret = root;

    return;
  }

  SecondLargestUtil(root->left, counter, ret);
}

int SecondLargest(Node* root) {
  int counter = 0;
  Node* ret = NULL;

  SecondLargestUtil(root, counter, &ret);

  return ret->data;
}

int main() {
  Node* root_1 = NULL;
  root_1 = Insert(root_1, 3);
  Insert(root_1, 1);
  Insert(root_1, 4);
  Insert(root_1, 0);
  Insert(root_1, 2);
  Insert(root_1, 5);
  cout << (SecondLargest(root_1) == 4 ? 1 : 0) << endl;

  Node* root_2 = NULL;
  root_2 = Insert(root_2, 1);
  Insert(root_2, 3);
  cout << (SecondLargest(root_2) == 1 ? 1 : 0) << endl;

  return 0;
}