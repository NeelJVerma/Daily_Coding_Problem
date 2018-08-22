/*
Given the sequence of keys visited by a postorder traversal of a binary search tree, reconstruct the tree.

For example, given the sequence 2, 4, 3, 8, 7, 5, you should construct the following tree:

    5
   / \
  3   7
 / \   \
2   4   8
*/

#include <iostream>

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

Node* ConstructTree(int* arr, int size) {
  Node* root = NULL;

  for (int i = size - 1; i >= 0; i--) {
    root = Insert(root, arr[i]);
  }
}

void Print(Node* root) {
  if (root) {
    Print(root->left);
    Print(root->right);
    std::cout << root->data << std::endl;
  }
}

int main() {
  int arr_1[] = {1, 7, 8, 6, 5, 4};
  Node* root = ConstructTree(arr_1, 6);
  Print(root);

  std::cout << std::endl;

  int arr_2[] = {2, 4, 3, 8, 7, 5};
  Node* root_2 = ConstructTree(arr_2, 6);
  Print(root_2);

  return 0;
}