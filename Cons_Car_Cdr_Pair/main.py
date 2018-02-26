"""
cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and
last element of that pair. Given the implementation of cons (below), implement
car and cdr.
"""

def cons(a, b):
    return lambda f: f(a, b)

def car(pair):
    return pair(lambda p, q: p)

def cdr(pair):
    return pair(lambda p, q: q)

print(True if car(cons(3, 4)) == 3 else False)
print(True if cdr(cons(3, 4)) == 4 else False)
print(True if car(cons(-1, 0)) == -1 else False)
print(True if cdr(cons(-1, 0)) == 0 else False)
