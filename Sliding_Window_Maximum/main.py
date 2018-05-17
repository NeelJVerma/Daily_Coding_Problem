"""
Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results. You can simply print them out as you compute them.

I stored them in a list and returned it so that I could verify that my answers were right quickly, but to satisfy the space constraint,
printing them would be best.
"""

from sys import maxsize

def sliding_window_maximum(l, k):
    deque = []
    maximums = []

    for i in range(k):
        while deque and l[i] >= l[deque[len(deque) - 1]]:
            deque.pop(len(deque) - 1)

        deque.append(i)

    for i in range(k, len(l)):
        maximums.append(l[deque[0]])

        while deque and deque[0] <= i - k:
            deque.pop(0)
 
        while deque and l[i] >= l[deque[len(deque) - 1]]:
            deque.pop(len(deque) - 1)

        deque.append(i)
 
    maximums.append(l[deque[0]])

    return maximums

print(True if sliding_window_maximum([1, 7, 6, 8, 9], 3) == [7, 8, 9] else False)
print(True if sliding_window_maximum([1], 1) == [1] else False)
print(True if sliding_window_maximum([1, 2], 1) == [1, 2] else False)
print(True if sliding_window_maximum([1, 7, 6, 8, 9], 4) == [8, 9] else False)
print(True if sliding_window_maximum([1, 2, 3, 4, 5], 2) == [2, 3, 4, 5] else False)
print(True if sliding_window_maximum([5, 4, 3, 2, 100], 2) == [5, 4, 3, 100] else False)