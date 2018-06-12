/*
Given a binary tree, return all paths from the root to leaves.

For example, given the tree

   1
  / \
 2   3
    / \
   4   5
it should return [[1, 2], [1, 3, 4], [1, 3, 5]].
*/

#include <iostream>
#include <vector>
using namespace std;

#define pb push_back

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

void PathsToRootUtil(Node* node, vector<int> path, vector<vector<int>>& all_paths) {
  if (!node) {
    return;
  }

  path.pb(node->data);

  if (!node->left && !node->right) {
    all_paths.pb(path);

    return;
  }

  PathsToRootUtil(node->left, path, all_paths);
  PathsToRootUtil(node->right, path, all_paths);
}

vector<vector<int>> PathsToRoot(Node* node) {
  vector<int> path;
  vector<vector<int>> all_paths;

  PathsToRootUtil(node, path, all_paths);

  return all_paths;
}

int main() {
  Node* root = AddNode(1);
  root->left = AddNode(2);
  root->right = AddNode(3);
  root->right->left = AddNode(4);
  root->right->right = AddNode(5);

  vector<vector<int>> all_paths = PathsToRoot(root);

  for (vector<int> v : all_paths) {
    for (int i : v) {
      cout << i << ' ';
    }

    cout << endl;
  }

  return 0;
}