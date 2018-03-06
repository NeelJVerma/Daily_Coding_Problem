"""
Problem statement: Imagine you are going up a set of steps. If you can only
take 1 or 2 step hops, what is the number of unique ways you can go up N steps.
What if instead of just 1 or 2, you could choose from a set of any number of
steps? For example, {1, 3, 5}.
"""

def get_ways(n, setofsteps):
    dp = [0 for x in range(n + 1)]
    dp[0] = 1

    for i in range(n + 1):
        dp[i] += sum(dp[i - step] for step in setofsteps if i - step > 0)
        dp[i] += 1 if i in setofsteps else 0

    return dp[-1]

print(True if get_ways(4, [1, 2]) == 5 else False)
print(True if get_ways(4, [1]) == 1 else False)
print(True if get_ways(1, [1, 2, 3]) == 1 else False)
print(True if get_ways(6, [1, 7, 9]) == 1 else False)
print(True if get_ways(5, [1, 2, 3, 4]) == 15 else False)
