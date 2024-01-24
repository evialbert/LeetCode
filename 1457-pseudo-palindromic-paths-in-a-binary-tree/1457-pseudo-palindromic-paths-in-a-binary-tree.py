# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pseudoPalindromicPaths (self, root: Optional[TreeNode]) -> int:
        def dfs(x, freq):
            if not x:
                return 0
            
            freq ^= 1 << x.val

            if not x.left and not x.right: 
                return int(freq.bit_count() <= 1)
            else:
                return dfs(x.left, freq) + dfs(x.right, freq)

        return dfs(root, 0) 
            