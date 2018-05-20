"""
A Python implementation of a binary search tree. Written
by Neel Verma.
"""

from random import randint

class Node:
    """
    Node class. This class initializes each node to be
    inserted into the tree.

    Attributes:
        data: The data of the node.
        left: a pointer to the left child of the node.
        right: a pointer to the right child of the node.
    """

    def __init__(self, data=0, left=None, right=None):
        """
        The function to initialize the class.

        Args:
            data: The data to be assigned to self.data.
            left: The pointer to be assigned to self.left.
            right: The pointer to be assigned to self.right.

        Returns:
            Returns nothing.
        """

        self.data = data
        self.left = left
        self.right = right

    def get_data(self):
        """
        A function to return the data of a particular node.

        Args:
            No args.

        Returns:
            Returns the data of said node.
        """

        return self.data

    def set_data(self, data):
        """
        A function to set the data of a particular node.

        Args:
            data: The data to assign to said node.

        Returns:
            Returns nothing.
        """

        self.data = data

class BST:
    """
    A binary search tree class. This class creates an object of
    type BST and has functions to perform operations on a particular
    binary search tree.

    Attributes:
        root: The root node of the binary search tree.
    """

    def __init__(self, root=None):
        """
        A function to initialize the class.

        Args:
            root: A root node to initialize the tree with.

        Returns:
            Returns nothing.
        """

        self.root = root

    def set_root(self, data):
        """
        A function to set the root of the binary search tree.

        Args:
            data: The data that the root contains.

        Returns:
            Returns nothing.
        """

        self.root = Node(data)

    def __insert_helper(self, currentnode, data):
        """
        A recursive helper function to insert a node.

        Args:
            currentnode: The current node that we are looking at.
            Eventually, the current node will filter down to its
            correct spot.
            data: The data that the current node contains.

        Returns:
            Returns nothing.
        """

        if data <= currentnode.data:
            if currentnode.left:
                self.__insert_helper(currentnode.left, data)
            else:
                currentnode.left = Node(data)
        else:
            if currentnode.right:
                self.__insert_helper(currentnode.right, data)
            else:
                currentnode.right = Node(data)

    def insert(self, data):
        """
        A function to insert a value into the tree. It calls a helper
        function because when inserting multiple values, it's best not
        to pass root outside of the class.

        Args:
            data: The data to be inserted into the tree.

        Returns:
            Returns nothing.
        """

        if not self.root:
            self.set_root(data)
        else:
            self.__insert_helper(self.root, data)

    def __find_helper(self, currentnode, data):
        """
        A recursive helper function to find a value in the tree.

        Args:
            currentnode: The current node that we are looking at.
            The current node will eventually reach the node with
            the given value or the end of the tree if it is not
            found.
            data: The value to search for.

        Returns:
            Returns true if the value is at the current node, otherwise
            return false.
        """

        if not currentnode:
            return False
        elif data == currentnode.data:
            return True
        elif data < currentnode.data:
            return self.__find_helper(currentnode.left, data)
        else:
            return self.__find_helper(currentnode.right, data)

    def find(self, data):
        """
        A function to find a value in the tree. It calls a helper
        function because when finding a value, we don't want to
        pass in root outside of the class.

        Args:
            data: The data to be searched for in the tree.

        Returns:
            Returns true if the value is found, false otherwise.
        """

        return self.__find_helper(self.root, data)

    def __print_tree_helper(self, currentnode):
        """
        A recursive helper function to print the tree in inorder.

        Args:
            currentnode: The node to start printing from.

        Returns:
            Returns nothing.
        """

        if currentnode:
            self.__print_tree_helper(currentnode.left)
            print(currentnode.data)
            self.__print_tree_helper(currentnode.right)

    def print_tree(self):
        """
        A function to print the tree in preorder. It calls a helper function
        because, once again, we do not want to pass the root outside of the
        class.

        Args:
            No args.

        Returns:
            Returns nothing.
        """

        self.__print_tree_helper(self.root)

    def print_level_order(self):
        """
        A function to do a breadth first traversal on the tree. We don't need
        to use a helper because we don't need to pass root to the function in
        main. We use a list as a queue to simulate FIFO behavior.

        Args:
            No args.

        Returns:
            Returns nothing.
        """

        queueofnodes = []
        queueofnodes.append(self.root)
        while queueofnodes:
            currentnode = queueofnodes[0]
            print(currentnode.data)
            if currentnode.left:
                queueofnodes.append(currentnode.left)
            if currentnode.right:
                queueofnodes.append(currentnode.right)
            del queueofnodes[0]