/*
Given a singly linked list and an integer k, remove the kth last element from the list. k is guaranteed to be smaller than the length of the list.

The list is very long, so making more than one pass is prohibitively expensive.

Do this in constant space and in one pass.
*/

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

void AddNode(Node** head, int data) {
  Node* new_node = new Node;
  Node* current = *head;
  new_node->data = data;
  new_node->next = NULL;

  if (!(*head)) {
    *head = new_node;

    return;
  }

  while (current->next) {
    current = current->next;
  }

  current->next = new_node;
}

void Print(Node* head) {
  Node* current = head;

  while (current) {
    cout << current->data << endl;
    current = current->next;
  }
}

void PopFront(Node** head) {
  Node* temp = *head;
  *head = (*head)->next;
  delete temp;
}

void Remove(Node** head, Node** previous, Node** current) {
  Node* temp = *current;
  (*previous)->next = (*current)->next;
  delete temp;
}

void RemoveKthLast(Node** head, int k) {
  Node* current = *head;
  Node* lagging = *head;
  Node* previous = NULL;

  for (int i = 0; i < k; i++) {
    current = current->next;
  }

  while (current->next) {
    previous = lagging;
    current = current->next;
    lagging = lagging->next;
  }

  if (lagging == *head) {
    PopFront(head);
  } else {
    Remove(head, &previous, &lagging);
  }
}

int main() {
  Node* head = NULL;
  AddNode(&head, 1);
  AddNode(&head, 2);
  AddNode(&head, 3);
  AddNode(&head, 4);
  AddNode(&head, 5);
  Print(head);
  RemoveKthLast(&head, 0);
  cout << endl;
  Print(head);
  
  return 0;
}