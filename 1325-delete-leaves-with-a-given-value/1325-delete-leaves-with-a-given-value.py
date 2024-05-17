# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:

        def myfun(root):
            if root:
                if root.left and (root.left.left or root.left.right):
                    myfun(root.left)
                if root.right and (root.right.left or root.right.right):
                    myfun(root.right)
                if root.left and not root.left.left and not root.left.right and root.left.val==target:
                    root.left=None
                if root.right and not root.right.left and not root.right.right and root.right.val==target:
                    root.right=None
                return root
        x=myfun(root)
        if x and not x.left and not x.right and x.val==target:
            return None
        return x