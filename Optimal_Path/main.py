"""
You are given an M by N matrix consisting of booleans that represents a board. Each True boolean represents a wall. Each False boolean represents a tile you can walk on.

Given this matrix, a start coordinate, and an end coordinate, return the minimum number of steps required to reach the end coordinate from the start. If there is no possible path, then return null. You can move up, left, down, and right. You cannot move through walls. You cannot wrap around the edges of the board.

For example, given the following board:

[[f, f, f, f],
[t, t, f, t],
[f, f, f, f],
[f, f, f, f]]
and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number of steps required to reach the end is 7, since we would need to go through (1, 2) because there is a wall everywhere else on the second row.
"""

def is_valid(matrix, cell, m, n):
    return ((cell[0] < m and cell[0] >= 0) and
           (cell[1] < n and cell[1] >= 0) and
           (not matrix[cell[0]][cell[1]]))

def get_up(visitedcell):
    return (visitedcell[0] - 1, visitedcell[1])

def get_left(visitedcell):
    return (visitedcell[0], visitedcell[1] - 1)

def get_right(visitedcell):
    return (visitedcell[0], visitedcell[1] + 1)

def get_down(visitedcell):
    return (visitedcell[0] + 1, visitedcell[1])

def optimal_path(matrix, start, end, m, n):
    queue = []
    visited = set()
    distances = {}

    if start[0] and start[1]:
        return None

    queue.append(start)
    distances[start] = 0

    while queue:
        visitedcell = queue[0]

        queue.pop(0)

        if visitedcell in visited:
            continue

        if visitedcell[0] == end[0] and visitedcell[1] == end[1]:
            return distances[visitedcell]

        visited.add(visitedcell)

        up = get_up(visitedcell)
        left = get_left(visitedcell)
        right = get_right(visitedcell)
        down = get_down(visitedcell)

        if is_valid(matrix, up, m, n):
            distances[up] = distances[visitedcell] + 1
            queue.append(up)

        if is_valid(matrix, left, m, n):
            distances[left] = distances[visitedcell] + 1
            queue.append(left)

        if is_valid(matrix, right, m, n):
            distances[right] = distances[visitedcell] + 1
            queue.append(right)

        if is_valid(matrix, down, m, n):
            distances[down] = distances[visitedcell] + 1
            queue.append(down)

print(True if optimal_path([[False, False, False, False],
                    [True, True, False, True],
                    [False, False, False, False],
                    [False, False, False, False]], (3, 0), (0, 0), 4, 4) == 7 else False)

print(True if optimal_path([[False, False, False, False],
                    [True, True, False, True],
                    [False, False, False, False],
                    [False, False, False, False]], (2, 0), (3, 0), 4, 4) == 1 else False)

print(True if optimal_path([[False, False, False, False],
                    [True, True, False, True],
                    [False, False, False, False],
                    [False, False, False, False]], (1, 0), (1, 1), 4, 4) == None else False)

print(True if optimal_path([[False, False, True, False],
                    [True, True, False, True],
                    [False, False, False, False],
                    [False, False, False, False]], (0, 0), (2, 0), 4, 4) == None else False)

print(True if optimal_path([[False, False, False, False],
                    [True, True, False, True],
                    [False, False, False, False],
                    [False, False, False, False]], (0, 0), (3, 2), 4, 4) == 5 else False)