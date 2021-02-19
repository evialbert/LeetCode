# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        if postorder==[]:
            return None 
        val=postorder[-1]
        index=inorder.index(val)
        root=TreeNode(val)
        left=self.buildTree(inorder[:index],postorder[:index])
        
        root.right=self.buildTree(inorder[index+1:],postorder[index:-1])
        root.left=left
        
        return root