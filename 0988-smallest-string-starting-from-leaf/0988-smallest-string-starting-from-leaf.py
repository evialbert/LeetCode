# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        self.ans = []

        def solution(root,res):
            if root.left:
                solution(root.left,res+chr(97+root.val))
            if root.right:
                solution(root.right,res+chr(97+root.val))
            if not root.left and not root.right:
                res+=chr(97+root.val)
                self.ans.append(res[::-1])
        solution(root,'')
        self.ans.sort()
        return self.ans[0]