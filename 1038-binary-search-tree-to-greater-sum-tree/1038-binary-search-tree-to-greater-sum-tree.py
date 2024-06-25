# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        self.running_sum = 0
        
        def reverse_inorder(node):
            if not node:
                return
            # Traverse the right subtree first
            reverse_inorder(node.right)
            # Update the node's value with the running sum
            self.running_sum += node.val
            node.val = self.running_sum
            # Traverse the left subtree
            reverse_inorder(node.left)
        
        reverse_inorder(root)
        return root