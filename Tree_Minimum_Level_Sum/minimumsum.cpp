/*
Given a binary tree, return the level of the tree with minimum sum.
*/

#include <iostream>
#include <queue>
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

int MinimumSumLevel(Node* root) {
  queue<Node*> q;
  q.push(root);
  int min_level = 0;
  int level = 0;
  int min_sum = root->data;

  while (!q.empty()) {
    int node_count = q.size();
    int sum = 0;

    while (node_count--) {
      Node* visited = q.front();
      q.pop();
      sum += visited->data;

      if (visited->left) {
        q.push(visited->left);
      }

      if (visited->right) {
        q.push(visited->right);
      }
    }

    if (sum < min_sum) {
      min_sum = sum;
      min_level = level;
    }

    level++;
  }

  return min_level;
}

int main() {
  Node* root_1 = AddNode(10);
  root_1->left = AddNode(4);
  root_1->right = AddNode(3);
  root_1->right->left = AddNode(4);
  root_1->right->right = AddNode(5);
  cout << (MinimumSumLevel(root_1) == 1 ? 1 : 0) << endl;

  Node* root_2 = AddNode(1);
  root_2->left = AddNode(-1);
  root_2->right = AddNode(-1);
  cout << (MinimumSumLevel(root_2) == 1 ? 1 : 0) << endl;

  Node* root_3 = AddNode(1);
  root_3->left = AddNode(4);
  root_3->right = AddNode(3);
  root_3->right->left = AddNode(4);
  root_3->right->right = AddNode(5);
  cout << (MinimumSumLevel(root_3) == 0 ? 1 : 0) << endl;

  return 0;
}