# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """ 
        if not root:
            return []
        stack=[root]
        res=[]
        while stack:
            
            stack1=[]
            while stack:
                node=stack.pop()
                stack1.append(node) 
            res.append(stack1[-1].val)
            while stack1:
                node=stack1.pop()
                if node.right:
                    stack.append(node.right)
                if node.left:
                    stack.append(node.left) 
        return res