# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, sum_: int) -> List[List[int]]:
        res = []
        if not root:
            return 
        stack = [(root,[root.val])]
        
        while stack:
            node,val_list = stack.pop()
            if not node.left and not node.right:
                if sum(val_list) == sum_:
                    res.append(val_list)
            if node.left:
                leftlist = val_list + [node.left.val]
                stack.append((node.left,leftlist))
            if node.right:
                rightlist = val_list+[node.right.val]
                stack.append((node.right,rightlist))
            
        return res