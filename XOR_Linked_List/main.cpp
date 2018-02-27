#include <iostream>
#include <cstdint>
using namespace std;

struct Node {
  int data;
  Node* both;
};

Node* Xor(Node* node_one, Node* node_two) {
  return (Node*) ((uintptr_t) (node_one) ^ (uintptr_t) (node_two));
}

void Add(Node** head, int data) {
  Node* node = new Node;

  node->data = data;
  node->both = Xor(*head, NULL);

  if (*head) {
    Node* next = Xor((*head)->both, NULL);

    (*head)->both = Xor(node, next);
  }

  *head = node;
}

void Print(Node* head) {
  Node* curr = head;
  Node* prev = NULL;
  Node* next = NULL;

  while (curr) {
    cout << curr->data << endl;

    next = Xor(prev, curr->both);
    prev = curr;
    curr = next;
  }
}

int Get(Node* head, int index) {
  int i = 0;
  Node* curr = head;
  Node* prev = NULL;
  Node* next = NULL;

  while (curr) {
    if (i == index) {
      return curr->data;
    }

    next = Xor(prev, curr->both);
    prev = curr;
    curr = next;

    i++;
  }
}

int main() {
  Node* head = NULL;

  Add(&head, 7);
  Add(&head, 8);
  Add(&head, 999);
  Add(&head, 27);

  Print(head);

  cout << endl;

  cout << Get(head, 0) << endl;
  cout << Get(head, 1) << endl;
  cout << Get(head, 2) << endl;
  cout << Get(head, 3) << endl;

  return 0;
}
