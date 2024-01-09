# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def collect_leaves(root):
            if not root: return []
            return collect_leaves(root.left) + ([root.val] if not root.left and not root.right else []) + collect_leaves(root.right)
        
        return collect_leaves(root1) == collect_leaves(root2)