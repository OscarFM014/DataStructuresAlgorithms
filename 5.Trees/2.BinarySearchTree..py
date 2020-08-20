class Node(object):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


class BST(object):
    def __init__(self, root):
        self.root = Node(root)

    def insert(self, new_val):
        node = Node(new_val)
        self.recursiveInsert(tree.root, node)

    def recursiveInsert(self, root, node):
        if (node < root.value):
            if(root.left):
                self.recursiveInsert(root.left, node)
            else:
                root.left = node
        else:
            if(root.right):
                self.recursiveInsert(root.right, node)
            else:
                root.right = node

    def search(self, find_val):
        return self.searchRecursive(tree.root, find_val)

    def searchRecursive(self, root, find_val):
        if(find_val == root.value):
            return True

        if(find_val < root.value):
            if(root.left):
                return self.searchRecursive(root.left, find_val)
            else:
                return False
        else:
            if(root.right):
                return self.searchRecursive(root.right, find_val)
            else:
                return False

        # Set up tree
tree = BST(4)

# Insert elements
tree.insert(2)
tree.insert(1)
tree.insert(3)
tree.insert(5)

# Check search
# Should be True
print(tree.search(4))
# Should be False
print(tree.search(6))
# Test
print(tree.search(5))
