# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        def dfs(root, tmp):
            if root is None:
                return
            dfs(root.right,tmp)
            dfs(root.left,tmp)
            root.right = tmp.pop()
            root.left = None
            tmp.append(root)
            return root
        return dfs(root, [None])   