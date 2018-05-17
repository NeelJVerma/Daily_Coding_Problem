"""
Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.
"""

def scheduler(l):
    l = sorted(l, key=lambda x: x[1])
    queue = []
    rooms = 1

    queue.append(l[0])

    for i in range(1, len(l)):
        while queue and queue[0][1] <= l[i][0]:
            queue.pop(0)

        queue.append(l[i])

        rooms = max(rooms, len(queue))

    return rooms

print(True if scheduler([(0, 50), (30, 75), (60, 150)]) == 2 else False)
print(True if scheduler([(0, 50), (30, 75)]) == 2 else False)
print(True if scheduler([(0, 50)]) == 1 else False)
print(True if scheduler([(1, 2), (4, 5), (4, 8), (4, 7)]) == 3 else False)
print(True if scheduler([(4, 5), (5, 16), (1, 2)]) == 1 else False)