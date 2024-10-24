# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        
        if root1 is None and root2 is None:
            return True

        elif root1 is None or root2 is None:
            return False

        elif root1.val != root2.val:
            return False

        if (root1.left and root2.left and root1.left.val == root2.left.val) or (root1.right and root2.right and root1.right.val == root2.right.val):
            # no swap
            if self.flipEquiv(root1.left, root2.left) and self.flipEquiv(root1.right, root2.right):
                return True

        else:
            # swap
            if self.flipEquiv(root1.left, root2.right) and self.flipEquiv(root1.right, root2.left):
                return True
        
        return False
