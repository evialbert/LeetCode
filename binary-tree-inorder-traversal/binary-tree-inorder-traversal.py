# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> list:
        res = []
        def pre_order(tree):
            if tree==None:
                return
            pre_order(tree.left)
            res.append(tree.val)
            pre_order(tree.right)
        pre_order(root)
        return res