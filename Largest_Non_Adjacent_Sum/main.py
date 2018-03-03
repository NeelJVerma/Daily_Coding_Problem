"""
Problem statement: Given a list of integers, write a function that returns the
largest sum of non-adjacent numbers. Numbers can be 0 or negative.

Time complexity: O(n)
"""

def largest_sum(l):
    include = l[0]
    exclude = 0

    for i in range(1, len(l)):
        temp = include if include > exclude else exclude
        include = exclude + l[i]
        exclude = temp

    return include if include > exclude else exclude

print(True if largest_sum([5, 1, 1, 5]) == 10 else False)
print(True if largest_sum([1, 2, 3, 4]) == 6 else False)
print(True if largest_sum([1, 1, 1, 1, 1, 1, 1]) == 4 else False)
print(True if largest_sum([9]) == 9 else False)
print(True if largest_sum([-5, -3, 1, 0, -2]) == 1 else False)
