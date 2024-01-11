# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        def recursion(node, min_, max_):
            if node is None:
                return 0
            
            current = max(node.val - min_, max_ - node.val)
            min_ = min(min_, node.val)
            max_ = max(max_, node.val)

            return max(
                current,
                recursion(node.left, min_, max_),
                recursion(node.right, min_, max_),
            )
        
        return recursion(root, root.val, root.val)
