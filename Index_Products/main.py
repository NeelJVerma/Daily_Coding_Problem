"""
Problem statement: Given an array of integers, return a new array such that
each element of the new array is the product of all numbers in the original
array except the one at index i. Solve it without using division and in O(n)
time.
"""

def index_products(l):
    n = len(l)

    if n == 0:
        return []

    left = [0 for i in range(n)]
    right = [0 for i in range(n)]

    left[0] = 1
    right[n - 1] = 1

    for i in range(1, n):
        left[i] = left[i - 1] * l[i - 1]

    for i in range(n - 2, -1, -1):
        right[i] = right[i + 1] * l[i + 1]

    returnl = [0 for i in range(n)]

    for i in range(n):
        returnl[i] = left[i] * right[i]

    return returnl

print(True if index_products([1, 2, 3, 4, 5]) == [120, 60, 40, 30, 24] else False)
print(True if index_products([1, 2, 3]) == [6, 3, 2] else False)
print(True if index_products([1]) == [1] else False)
print(True if index_products([]) == [] else False)
print(True if index_products([5, 5, 5]) == [25, 25, 25] else False)
print(True if index_products([100, -100, 1]) == [-100, 100, -10000] else False)
