# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        # convert BST tree to a sorted array:
        def bstToArrayInorder(root, arr):
            if root is None:
                return
            bstToArrayInorder(root.left, arr)
            arr.append(root.val)
            bstToArrayInorder(root.right, arr)
            return
        
        def bstBalancedConstructerFromSortedArray(arr):
            if not arr:
                return None
            
            mid = len(arr) // 2

            root = TreeNode(arr[mid])
            root.left = bstBalancedConstructerFromSortedArray(arr[:mid])
            root.right = bstBalancedConstructerFromSortedArray(arr[mid+1:])
            
            return root

        arr = []
        bstToArrayInorder(root, arr)
        
        return bstBalancedConstructerFromSortedArray(arr)