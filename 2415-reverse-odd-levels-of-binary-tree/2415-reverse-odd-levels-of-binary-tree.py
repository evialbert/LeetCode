# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque 

class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        q = deque([root])
        level = 0 
        while q:
            nodes = []
            for _ in range(len(q)):
                sub_tree_root = q.popleft()
                nodes.append(sub_tree_root)
                if sub_tree_root.left is not None:
                    q.append(sub_tree_root.left)
                    q.append(sub_tree_root.right)
            
            if level % 2 == 1:
                l = 0
                r = len(nodes) - 1
                while l < r:
                    nodes[l].val, nodes[r].val = nodes[r].val, nodes[l].val
                    l += 1
                    r -= 1
            
            level += 1
        
        return root