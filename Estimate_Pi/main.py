"""
The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.
"""

import random

ITERATIONS = 1000000

def estimate_pi():
    pointsincircle = 0
    pi = float()

    for i in range(ITERATIONS):
        randomx = random.uniform(0.0, 1.0)
        randomy = random.uniform(0.0, 1.0)
        distance = (randomx ** 2) + (randomy ** 2)

        if distance <= 1:
            pointsincircle += 1

        pi = 4 * (pointsincircle / ITERATIONS)

    return pi

print(estimate_pi())