class Node:
    def __init__(self, data):
        self.nextn = None
        self.data = data

class List:
    def __init__(self):
        self.head = None
        self.tail = None

    def empty(self):
        return self.head == None and self.tail == None

    def push_back(self, data):
        current = Node(data)
        if self.empty():
            self.head = current
            self.tail = current
        else:
            self.tail.nextn = current
            self.tail = current

    def push_front(self, data):
        current = Node(data)
        if self.empty():
            self.head = current
            self.tail = current
        else:
            current.nextn = self.head
            self.head = current

    def pop_back(self):
        if self.empty():
            return
        current = self.head
        prev = None
        while current != self.tail:
            prev = current
            current = current.nextn
        prev.nextn = None
        self.tail = prev

    def pop_front(self):
        if self.empty():
            return
        self.head = self.head.nextn

    def delete_node(self, node):
        if node == self.head or node == self.tail:
            return
        else:
            node.data = node.nextn.data
            node.nextn = node.nextn.nextn
        
    def print_list(self):
        current = self.head
        while current is not None:
            print(current.data)
            current = current.nextn