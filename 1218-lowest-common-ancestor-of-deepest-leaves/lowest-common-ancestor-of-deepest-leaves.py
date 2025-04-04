# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def maxdepth(node,d): # to find depth of the tree T(n) S(h)
            d1,d2=0,0
            if not node:
                return d
            if node and node.left:
                d2=maxdepth(node.left,d+1)
            if node and node.right:
                d1=maxdepth(node.right,d+1)
            return max(d1,d2,d)
        self.depth=maxdepth(root,0) #S(1)
        self.lon=[] # S(h)
        def dfs(node,d,path): # T(n) S(h)
            if node and d==self.depth:
                path+=[node]
                if self.lon==[]:
                    self.lon=path
                    return
                i=0
                while i<len(self.lon): # runs for h time but after each iteration it becomes h-1 which can run for worst case of n/2 times
                    # this follows the pattern of sum of first n natural number but reverse so its h**2 complexity in worst case where its a complete binary tree with all levels filled
                    if self.lon[i]==path[i]:
                        i+=1
                    else:
                        self.lon=self.lon[:i]
                        break
            if not node:
                return
            if node and node.left:
                dfs(node.left,d+1,path+[node])
            if node and node.right:
                dfs(node.right,d+1,path+[node])
        dfs(root,0,[])
        return self.lon[-1]
