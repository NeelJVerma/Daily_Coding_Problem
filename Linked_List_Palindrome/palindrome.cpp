/*
Determine whether a doubly linked list is a palindrome. What if it’s singly linked?

For example, 1 -> 4 -> 3 -> 4 -> 1 returns true while 1 -> 4 returns false.
*/

#include <iostream>
#include <stack>
using namespace std;

/**********************
 * DOUBLY LINKED LIST *
 **********************/

struct DllNode {
  int data;
  DllNode* prev;
  DllNode* next;
};

void AddNodeDoubly(DllNode** head, int data) {
  DllNode* new_node = new DllNode;
  DllNode* current = *head;
  new_node->data = data;
  new_node->next = NULL;

  if (!(*head)) {
    new_node->prev = NULL;
    *head = new_node;

    return;
  }

  while (current->next) {
    current = current->next;
  }

  current->next = new_node;
  new_node->prev = current;
}

bool IsPalindromeDoubly(DllNode* head) {
  DllNode* current_back = head;
  DllNode* current_front = head;

  while (current_back->next) {
    current_back = current_back->next;
  }

  while (current_front != current_back) {
    if (current_front->data != current_back->data) {
      return false;
    }

    current_front = current_front->next;
    current_back = current_back->prev;
  }

  return true;
}

/**********************
 * SINGLY LINKED LIST *
 **********************/

struct SllNode {
  int data;
  SllNode* next;
};

void AddNodeSingly(SllNode** head, int data) {
  SllNode* new_node = new SllNode;
  SllNode* current = *head;
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

bool IsPalindromeSingly(SllNode* head) {
  int size = 0;
  SllNode* current = head;

  while (current) {
    size++;
    current = current->next;
  }

  current = head;
  stack<int> first_half;
  int i;

  for (i = 0; i < size / 2; i++) {
    first_half.push(current->data);
    current = current->next;
  }

  int resume;

  if (size & 1) {
    resume = i + 1;
    current = current->next;
  } else {
    resume = i;
  }

  while (current) {
    if (current->data != first_half.top()) {
      return false;
    }

    first_half.pop();
    current = current->next;
  }

  return true;
}

int main() {
  DllNode* head_1 = NULL;
  AddNodeDoubly(&head_1, 1);
  AddNodeDoubly(&head_1, 4);
  AddNodeDoubly(&head_1, 3);
  AddNodeDoubly(&head_1, 4);
  AddNodeDoubly(&head_1, 1);
  cout << (IsPalindromeDoubly(head_1) ? 1 : 0) << endl;

  DllNode* head_2 = NULL;
  AddNodeDoubly(&head_2, 1);
  AddNodeDoubly(&head_2, 4);
  cout << (!IsPalindromeDoubly(head_2) ? 1 : 0) << endl;

  SllNode* head_3 = NULL;
  AddNodeSingly(&head_3, 1);
  AddNodeSingly(&head_3, 2);
  AddNodeSingly(&head_3, 2);
  AddNodeSingly(&head_3, 1);
  cout << (IsPalindromeSingly(head_3) ? 1 : 0) << endl;

  SllNode* head_4 = NULL;
  AddNodeSingly(&head_4, 1);
  AddNodeSingly(&head_4, 4);
  AddNodeSingly(&head_4, 3);
  cout << (!IsPalindromeSingly(head_4) ? 1 : 0) << endl;

  return 0;
}