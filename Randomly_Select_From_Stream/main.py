"""
Given a stream of elements too large to store in memory, pick a random element from the stream with uniform probability.
"""

import random

VISITED = 0
RESULT = 0

def select_random(stream):
    global VISITED
    global RESULT

    VISITED += 1

    if VISITED == 1:
        RESULT = stream[0]
    else:
        randomindex = random.randint(0, VISITED - 1)

        if randomindex == VISITED - 1:
            RESULT = stream[randomindex]

    return RESULT

l = []

for i in range(10):
    l.append(i)

for i in range(10):
    print(select_random(l))