"""
Problem statement: Given the mapping a = 1, b = 2, ..., z = 26 and an encoded
message, count the number of ways it can be decoded.
"""

def decode(s, n):
    if n == 0 or n == 1:
        return 1

    count = 0

    if s[n - 1] > '0':
        count = decode(s, n - 1)

    if s[n - 2] == '1' or (s[n - 2] == '2' and s[n - 1] <= '6'):
        count += decode(s, n - 2)

    return count

print(True if decode('111', 3) == 3 else False)
print(True if decode('123', 3) == 3 else False)
print(True if decode('126', 3) == 3 else False)
print(True if decode('127', 3) == 2 else False)
print(True if decode('2727', 4) == 1 else False)
print(True if decode('', 1) == 1 else False)
print(True if decode('1', 1) == 1 else False)
