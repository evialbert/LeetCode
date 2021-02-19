# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root == None:
            return []
        
        res = []            
        nodes = [root]
        while nodes:
            res.append( [ node.val for node in nodes] )
            next_nodes = [ ]
            for node in nodes:
                if node.left:
                	next_nodes.append(node.left)
                if node.right:
                    next_nodes.append(node.right)
            nodes = next_nodes
        
        return res
            
            
            
        