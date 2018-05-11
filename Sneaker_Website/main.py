"""
You run a sneaker website and want to record the last N order ids in a log.
Implement a data structure to accomplish this, with the following API:

record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. i is guaranteed to be
smaller than or equal to N.
You should be as efficient with time and space as possible.
"""

class OrderLogNode(object):
    def __init__(self, orderid):
        self.orderid = orderid
        self.next = None
        self.previous = None

    def get_order_id(self):
        return self.orderid

class OrderLog(object):
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def empty(self):
        return not self.head and not self.tail

    def record(self, orderid):
        current = OrderLogNode(orderid)

        if self.empty():
            self.head = current
            self.tail = current
        else:
            current.previous = self.tail
            self.tail.next = current
            self.tail = current

        self.size += 1

    def get_last(self, i):
        returnlist = []
        index = 0
        current = self.head

        while current:
            if index >= self.size - i:
                returnlist.append(current.orderid)

            index += 1
            current = current.next

        return returnlist

log = OrderLog()

for i in range(20):
    log.record(i)

print(True if log.get_last(0) == [] else False)
print(True if log.get_last(1) == [19] else False)
print(True if log.get_last(5) == [15, 16, 17, 18, 19] else False)
print(True if log.get_last(10) == [10, 11, 12, 13, 14, 15, 16, 17, 18, 19] else False)