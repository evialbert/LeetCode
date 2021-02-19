# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        node, stack = root, []
        prev = lo = hi = None 
        while stack or node:
            if node: 
                stack.append(node)
                node = node.left
                continue
            node = stack.pop()
            if prev and prev.val > node.val: #check symmetric order
                if not lo: lo, hi = prev, node
                else: hi = node 
            prev = node 
            node = node.right 
        lo.val, hi.val = hi.val, lo.val 