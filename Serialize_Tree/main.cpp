// Problem statement: Given a binary tree, provide the functionality to
// serialize it into a string and deserialize that string back into a tree.

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

struct Node {
  int key;
  Node* left;
  Node* right;
};

Node* AddNode(int key) {
  Node* temp = new Node;
  temp->key = key;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

void InOrder(Node* root) {
  if (root) {
    InOrder(root->left);
    cout << root->key << endl;
    InOrder(root->right);
  }
}

void serialize(Node* root, FILE* f) {
  if (!root) {
    fprintf(f, "%d ", -1);

    return;
  }

  fprintf(f, "%d ", root->key);

  serialize(root->left, f);
  serialize(root->right, f);
}

void deserialize(Node*& root, FILE* f) {
  int value;

  if (!fscanf(f, "%d", &value) || value == -1) {
    return;
  }

  root = AddNode(value);
  deserialize(root->left, f);
  deserialize(root->right, f);
}

int main() {
  Node* root = AddNode(5);
  root->left = AddNode(2);
  root->right = AddNode(7);
  root->left->right = AddNode(6);
  root->left->right->left = AddNode(4);
  root->right->left = AddNode(3);
  root->right->right = AddNode(45);

  InOrder(root);
  cout << endl;

  FILE* f = fopen("tree.txt", "w");

  serialize(root, f);
  fclose(f);

  Node* root2;

  f = fopen("tree.txt", "r");
  deserialize(root2, f);
  fclose(f);

  InOrder(root2);
  return 0;
}
