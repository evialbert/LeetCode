# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def addOneRow(self, root: TreeNode, v: int, d: int) -> TreeNode:
        if d == 1: return TreeNode(v, left=root) # edge case 
        queue = [root]
        while queue: 
            d -= 1
            if d == 1: 
                for node in queue: 
                    node.left = TreeNode(v, left=node.left)
                    node.right = TreeNode(v, right=node.right)
                break 
            newq = []
            for node in queue: 
                if node.left: newq.append(node.left)
                if node.right: newq.append(node.right)
            queue = newq
        return root 