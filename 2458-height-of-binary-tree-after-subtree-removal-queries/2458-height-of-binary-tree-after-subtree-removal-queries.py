# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def treeQueries(self, root: Optional[TreeNode], q : List[int]) -> List[int]:
        lvl =  defaultdict(int)
        mx = 0
        def level(node):
            nonlocal mx
            if not node:
                return 0
            l = level(node.left)
            r = level(node.right)
            lvl[node.val] = max(l,r) +1
            mx = max(mx, lvl[node.val])
            return lvl[node.val]
        level(root)
        n = len(lvl) + 3
        ans = [mx-1 for i in range(n+1)]
        curmx = 0
        def helper(node, cur):
            if not node:
                return 
            nonlocal curmx
            # print(node.val)
            l,r = 0,0
            if node.left:
                l = lvl[node.left.val] 
            if node.right:
                r = lvl[node.right.val] 
            if r > l:
                right = node.right.val
                curmx = max(curmx, cur + l)
                ans[right] = curmx
                helper(node.right, cur + 1)
            elif l > r:
                left = node.left.val
                curmx = max(curmx, cur + r)
                ans[left] = curmx
                helper(node.left, cur + 1)
            else:
                return
        helper(root, 0)
        return [ans[i] for i in q]