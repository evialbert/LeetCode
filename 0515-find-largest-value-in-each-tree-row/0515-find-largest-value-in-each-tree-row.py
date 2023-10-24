# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        d = collections.defaultdict(lambda : -sys.maxsize)
        def dfs(node, level):
            if not node: return 
            if node.val > d[level]:
                d[level] = node.val
            if node.left:    
                dfs(node.left, level+1)    
            if node.right:    
                dfs(node.right, level+1)    
        dfs(root, 0)        
        return d.values()