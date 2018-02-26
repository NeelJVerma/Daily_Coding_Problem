"""
Problem statement: Given an array of integers, find the first missing positive
integer in linear time and constant space.
"""

def separate(l, size):
    returnpos = 0

    for i in range(size):
        if l[i] <= 0:
            l[i], l[returnpos] = l[returnpos], l[i]

            returnpos += 1

    return returnpos

def find_missing_positive_helper(l, size):
    for i in range(size):
        if abs(l[i]) - 1 < size and l[abs(l[i]) - 1] > 0:
            l[abs(l[i]) - 1] = -l[abs(l[i]) - 1]

    for i in range(size):
        if l[i] > 0:
            return i + 1

    return size + 1

def find_missing_positive(l):
    size = len(l)

    shift = separate(l, size)

    return find_missing_positive_helper(l[shift:], size - shift)

print(True if find_missing_positive([1, 3, -1, 4]) == 2 else False)
print(True if find_missing_positive([1]) == 2 else False)
print(True if find_missing_positive([-1]) == 1 else False)
print(True if find_missing_positive([0]) == 1 else False)
print(True if find_missing_positive([-100, 2, 1, -22, 4]) == 3 else False)
