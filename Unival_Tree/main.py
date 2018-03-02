class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def add_node(data):
    node = Node(data)

    return node

count = 0

def count_unival(root):
    global count

    if not root:
        return True

    left = count_unival(root.left)
    right = count_unival(root.right)

    if not left or not right:
        return False

    if root.left and root.data != root.left.data:
        return False

    if root.right and root.data != root.right.data:
        return False

    count += 1

    return True

def print_tree(root):
    if root:
        print_tree(root.left)
        print(root.data)
        print_tree(root.right)

root = Node(5)

root.left = Node(4)
root.right = Node(5)
root.left.left = Node(4)
root.left.right = Node(4)
root.right.right = Node(5)

print_tree(root)

print()

count_unival(root)

print(True if count == 5 else False)
