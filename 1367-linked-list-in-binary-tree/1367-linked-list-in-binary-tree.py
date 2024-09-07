# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        lst = []
        while head:
            lst.append(head.val)
            head = head.next
        
        def dfs(node, indx):
            if indx < len(lst):
                if node:
                    if node.val == lst[indx]:
                        return dfs(node.left, indx + 1) or dfs(node.right, indx + 1)
                    else:
                        return False
                else:
                    return indx == len(lst)
            else:
                return True
        
        lst_nodes = []
        def run_tree(node):
            if node:
                if node.val == lst[0]:
                    lst_nodes.append(node)
                run_tree(node.left)
                run_tree(node.right)
        
        run_tree(root)
        ans = False
        for node in lst_nodes:
            ans = ans or dfs(node, 0)
        
        return ans