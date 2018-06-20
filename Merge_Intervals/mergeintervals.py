"""

Given a list of possibly overlapping intervals, return a new list of intervals where all overlapping intervals have been merged.

The input list is not necessarily ordered in any way.

For example, given [(1, 3), (5, 8), (4, 10), (20, 25)], you should return [(1, 3), (4, 10), (20, 25)].
"""

def merge_intervals(intervals):
    intervals = sorted(intervals, key=lambda x: x[0])
    previous = intervals[0]
    ret = []

    for i in range(1, len(intervals)):
        current = intervals[i]

        if current[0] > previous[1]:
            ret.append(previous)
            previous = current
        else:
            merged = (previous[0], max(previous[1], current[1]))
            previous = merged

    ret.append(previous)

    return ret


print(True if merge_intervals([(1, 3), (5, 8), (4, 10), (20, 25)]) == [(1, 3), (4, 10), (20, 25)] else False)
print(True if merge_intervals([(1, 3), (5, 15), (4, 10), (20, 25)]) == [(1, 3), (4, 15), (20, 25)] else False)
print(True if merge_intervals([(1, 3), (2, 4), (5, 7), (6, 8)]) == [(1, 4), (5, 8)] else False)