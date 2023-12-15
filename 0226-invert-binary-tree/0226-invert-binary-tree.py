# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return root

        old_left = root.left

        root.left = root.right 
        root.right = old_left

        if root.left is not None:
            root.left = self.invertTree(root.left)
        
        if root.right is not None:
            root.right = self.invertTree(root.right)

        return root
