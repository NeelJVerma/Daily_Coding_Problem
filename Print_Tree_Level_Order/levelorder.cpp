/*
Print the nodes in a binary tree level-wise. For example, the following should print 1, 2, 3, 4, 5.

  1
 / \
2   3
   / \
  4   5
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

void PrintLevelOrder(Node* root) {
  queue<Node*> q;
  q.push(root);

  while (!q.empty()) {
    Node* visited = q.front();
    cout << visited->data << endl;
    q.pop();

    if (visited->left) {
      q.push(visited->left);
    }

    if (visited->right) {
      q.push(visited->right);
    }
  }
}

int main() {
  Node* root = AddNode(1);
  root->left = AddNode(2);
  root->right = AddNode(3);
  root->right->left = AddNode(4);
  root->right->right = AddNode(5);

  PrintLevelOrder(root);

  return 0;
}