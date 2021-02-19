# Python3



# Definition for binary tree with next pointer.

# class TreeLinkNode:

#     def __init__(self, x):

#         self.val = x

#         self.left = None

#         self.right = None

#         self.next = None



"""
# Definition for a Node.
class Node:
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None or root.left is None:
            return root
        root.left.next = root.right
        if root.next:
            root.right.next = root.next.left
        self.connect(root.left)
        self.connect(root.right)
        return root
