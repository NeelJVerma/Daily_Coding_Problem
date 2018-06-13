/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree. Assume that each node in the tree also has a pointer to its parent.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

#define pb push_back

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

vector<Node*> GetParents(Node* n) {
  vector<Node*> parents;

  while (n) {
    parents.pb(n);
    n = n->parent;
  }

  return parents;
}

Node* LCA(Node* v, Node* w) {
  vector<Node*> v_parents = GetParents(v);
  vector<Node*> w_parents = GetParents(w);
  unordered_set<Node*> check;

  for (Node* n : v_parents) {
    check.insert(n);
  }

  for (Node* n : w_parents) {
    if (check.find(n) != check.end()) {
      return n;
    }
  }
}

int main() {
  Node* root = AddNode(1);
  root->parent = NULL;
  root->left = AddNode(2);
  root->left->parent = root;
  root->right = AddNode(3);
  root->right->parent = root;
  root->left->left = AddNode(4);
  root->left->left->parent = root->left;
  root->left->right = AddNode(5);
  root->left->right->parent = root->left;
  root->left->right->left = AddNode(6);
  root->left->right->left->parent = root->left->right;
  root->left->right->right = AddNode(7);
  root->left->right->right->parent = root->left->right;

  cout << (LCA(root, root->right)->data == 1 ? 1 : 0) << endl;
  cout << (LCA(root->left->right, root->left->left)->data == 2 ? 1 : 0) << endl;
  cout << (LCA(root->left->right, root->right)->data == 1 ? 1 : 0) << endl;
  cout << (LCA(root->left->right->left, root->left->right)->data == 5 ? 1 : 0) << endl;

  return 0;
}