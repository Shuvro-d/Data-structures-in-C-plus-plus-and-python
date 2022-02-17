from queue import Queue
from BinaryTreePrinter import BinaryTreePrinter


class TreeNode:
    def __init__(self,val):
        self.left=None
        self.right=None
        self.val=val

class BinaryTree:
    def __init__(self):
        self.root=None

    def insert(self,val):
        if self.root is None:
            self.root=TreeNode(val)
        else:
            nodes=Queue()
            nodes.enqueue(self.root)

            while True:
                checking_node=nodes.deque()
                if checking_node.left is None:
                    checking_node.left = TreeNode(val)
                    return
                elif checking_node.right is None:
                    checking_node.right = TreeNode(val)
                    return
                else:
                    nodes.enqueue(checking_node.left)
                    nodes.enqueue(checking_node.right)

    def __str__(self):
        tree_printer = BinaryTreePrinter()
        # tree_printer = BinaryTreePrinter(branch_line="_", extra_padding=0)
        return tree_printer.get_tree_string(self.root)


my_tree=BinaryTree()
my_tree.insert(1)
my_tree.insert(2)
my_tree.insert(3)
my_tree.insert(4)
my_tree.insert(5)
my_tree.insert(6)
my_tree.insert(7)
my_tree.insert(8)
print(my_tree)