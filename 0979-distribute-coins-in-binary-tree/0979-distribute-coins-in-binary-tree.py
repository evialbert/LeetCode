# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        res = 0

        def dfs(root: Optional[TreeNode]) -> int:
            if not root: return 0
            left = dfs(root.left)
            right = dfs(root.right)

            nonlocal res
            res += abs(left) + abs(right) + (root.val - 1)

            return left + right + (root.val - 1)
        
        dfs(root)
        return res