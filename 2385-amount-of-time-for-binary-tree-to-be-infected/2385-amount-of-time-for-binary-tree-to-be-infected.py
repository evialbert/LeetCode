# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def check(self,root,target):
        if(root==None):return 0,0,0
        lf,la,ld=self.check(root.left,target)
        rf,ra,rd=self.check(root.right,target)
        if(root.val==target):
            return 1,max(ld,rd),0
        elif(lf):
            return lf,max(la,ld+rd+1),ld+1
        elif(rf):
            return rf,max(ra,ld+rd+1),rd+1
        else:
            return 0,0,max(ld,rd)+1

    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        f,a,d=self.check(root,start)
        return a