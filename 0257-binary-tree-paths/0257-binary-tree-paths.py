# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        def dfs(root, path, res):
            if not root.left and not root.right:
                res.append(('->'.join([str(char) for char in path]) + '->' if path else "" ) + str(root.val))
                return
            if root.left:
                dfs(root.left, path + [root.val], res)
            if root.right:
                dfs(root.right, path + [root.val], res)
        
        res = []
        dfs(root, [], res)
        return res