# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        
        def traverse(node):
            if node != None:
                li.append(node.val)
                traverse(node.left)
                traverse(node.right)
        
        li = []
        traverse(root)
        
        ans = Counter(li)
        max_value = max(ans.values())
        return [key for key, value in ans.items() if value == max_value]