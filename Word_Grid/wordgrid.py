"""
Given a 2D board of characters and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example, given the following board:

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
exists(board, "ABCCED") returns true, exists(board, "SEE") returns true, exists(board, "ABCB") returns false.
"""

def dfs(matrix, word, i, j, k):
    m = len(matrix)
    n = len(matrix[0])

    if i < 0 or j < 0 or i >= m or j >= n:
        return False

    if matrix[i][j] == word[k]:
        temp = matrix[i][j]
        matrix[i][j] = '.'

        if k == len(word) - 1:
            return True

        if (dfs(matrix, word, i - 1, j, k + 1) or
            dfs(matrix, word, i + 1, j, k + 1) or
            dfs(matrix, word, i, j - 1, k + 1) or
            dfs(matrix, word, i, j + 1, k + 1)):
            return True

        matrix[i][j] = temp

    return False

def find_word(matrix, word):
    m = len(matrix)
    n = len(matrix[0])

    for i in range(m):
        for j in range(n):
            if dfs(matrix, word, i, j, 0):
                return True

    return False

matrix = [['A', 'B', 'C', 'E'], 
          ['S', 'F', 'C', 'S'],
          ['A', 'D', 'E', 'E']]

print(True if find_word(matrix, 'ABCCED') else False)

matrix = [['A', 'B', 'C', 'E'], 
          ['S', 'F', 'C', 'S'],
          ['A', 'D', 'E', 'E']]

print(True if find_word(matrix, 'SEE') else False)

matrix = [['A', 'B', 'C', 'E'], 
          ['S', 'F', 'C', 'S'],
          ['A', 'D', 'E', 'E']]

print(True if not find_word(matrix, 'ABCB') else False)