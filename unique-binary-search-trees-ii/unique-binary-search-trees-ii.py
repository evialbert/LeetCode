# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, n):
        if n == 0:
            return []
        def gen(s, e):
            if e == s:
                yield None
            elif e - s == 1:
                yield TreeNode(s, None, None)
            else:
                yield from (TreeNode(i, j, k) for i in range(s, e) for j in gen(s, i) for k in gen(i+1, e))
        yield from gen(1, n+1)