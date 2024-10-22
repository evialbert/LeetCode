# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        if not root:
            return -1
        result = []
        queue = deque([root])

        while queue:
            level_sum = 0
            level_len = len(queue)

            for _ in range(level_len):
                node = queue.popleft()
                level_sum += node.val
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            result.append(level_sum)

        sorted_sums = sorted(result, reverse=True)
        if k > len(sorted_sums):
            return -1
        return sorted_sums[k-1]