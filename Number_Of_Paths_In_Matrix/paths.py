"""
You are given an N by M matrix of 0s and 1s. Starting from the top left corner, how many ways are there to reach the bottom right corner?

You can only move right and down. 0 represents an empty space while 1 represents a wall you cannot walk through.

For example, given the following matrix:

[[0, 0, 1],
 [0, 0, 1],
 [1, 0, 0]]
Return two, as there are only two ways to get to the bottom right:

Right, down, down, right
Down, right, down, right
The top left corner and bottom right corner will always be 0.
"""

def num_paths(matrix):
    n = len(matrix)
    m = len(matrix[0])
    paths = [[0 for i in range(m)] for j in range(n)]

    for i in range(n):
        for j in range(m):
            if matrix[i][j] == 1:
                continue

            if i == 0 and j == 0:
                paths[i][j] = 1
            else:
                if i > 0:
                    paths[i][j] += paths[i - 1][j]

                if j > 0:
                    paths[i][j] += paths[i][j - 1]

    return paths[-1][-1]

print(True if num_paths([[0, 0, 1], [0, 0, 1], [1, 0, 0]]) == 2 else False)