/*
Given a stack of N elements, interleave the first half of the stack with the second half reversed using only one other queue. This should be done in-place.

Recall that you can only push or pop from a stack, and enqueue or dequeue from a queue.

For example, if the stack is [1, 2, 3, 4, 5], it should become [1, 5, 2, 4, 3]. If the stack is [1, 2, 3, 4], it should become [1, 4, 2, 3].
*/

#include <iostream>
#include <stack>
#include <queue>

void InterleaveStack(std::stack<int> to_interleave) {
  std::queue<int> intermediate;
  int num_to_pop = to_interleave.size();

  while (num_to_pop--) {
    for (int i = 0; i < num_to_pop; i++) {
      int to_push = to_interleave.top();
      to_interleave.pop();
      intermediate.push(to_push);
    }

    while (!intermediate.empty()) {
      int to_push = intermediate.front();
      to_interleave.push(to_push);
      intermediate.pop();
    }
  }

  while (!to_interleave.empty()) {
    std::cout << to_interleave.top() << std::endl;
    to_interleave.pop();
  }
}

int main() {
  std::stack<int> to_interleave_1;
  to_interleave_1.push(1);
  to_interleave_1.push(2);
  to_interleave_1.push(3);
  to_interleave_1.push(4);
  to_interleave_1.push(5);
  InterleaveStack(to_interleave_1);

  std::cout << std::endl;

  std::stack<int> to_interleave_2;
  to_interleave_2.push(1);
  to_interleave_2.push(2);
  to_interleave_2.push(3);
  to_interleave_2.push(4);
  InterleaveStack(to_interleave_2);

  return 0;
}