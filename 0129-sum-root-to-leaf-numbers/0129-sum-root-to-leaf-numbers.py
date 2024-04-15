# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorder(self, root, allPaths, path):
        if root is None:
            return 
        path += str(root.val)
        
        if root.left is None and root.right is None:
            allPaths.append(str(path))
        
        self.preorder(root.left, allPaths, path)
        self.preorder(root.right, allPaths, path)
        
        path = ''.join(list(path)[:len(path)-1])
        
    
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        allPaths, path = [], ""
        self.preorder(root, allPaths, path)
        totalSum = 0
        for path in allPaths:
            totalSum += int(path)
            
        return totalSum