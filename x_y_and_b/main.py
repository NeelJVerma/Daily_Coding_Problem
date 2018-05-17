"""
Given three 32-bit integers x, y, and b, return x if b is 1 and y if b is 0, using only mathematical or bit operations. You can assume b can only be 1 or 0.
"""

def x_or_y(x, y, b):
    if b & 1 == 1:
        return x

    return y

print(True if x_or_y(2, 3, 1) == 2 else False)
print(True if x_or_y(2, 3, 0) == 3 else False)
print(True if x_or_y(4, 5, 1) == 4 else False)
print(True if x_or_y(4, 5, 0) == 5 else False)