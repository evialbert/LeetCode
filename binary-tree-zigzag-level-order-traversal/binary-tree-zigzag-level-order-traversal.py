# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root: return []
        res = []
        queue = collections.deque([root])
        order = False
        while queue:
            level = []
            for i in range(len(queue)):
                node = queue.popleft()
                if order:
                    level = [node.val] + level # # level.insert(0, node.val)
                else:
                    level.append(node.val)
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)
            order = not(order)
            res.append(level)
        return res            