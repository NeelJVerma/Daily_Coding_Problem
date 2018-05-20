"""
Implement division of two positive integers without using the division, multiplication, or modulus operators. Return the quotient as an integer, ignoring the remainder.
"""

def divide(n, m):
    if m == 0:
        raise ValueError('Division by zero')

    count = 0
    start = m

    while start <= n:
        start += m
        count += 1

    return count

print(True if divide(24, 4) == 6 else False)
print(True if divide(100, 99) == 1 else False)
print(True if divide(100, 101) == 0 else False)
print(True if divide(50, 25) == 2 else False)
print(True if divide(77, 24) == 3 else False)