# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        queue = deque([root])
        ans = 0
        while len(queue)!=0:
            levelNode = []
            for k in range(len(queue)):
                nowNode = queue.popleft()
                levelNode.append(nowNode.val)
                if nowNode.left!=None:
                    queue.append(nowNode.left)
                if nowNode.right!=None:
                    queue.append(nowNode.right)
            
            levelNodeSort = sorted(levelNode)
            posDict = defaultdict(int)
            for i in range(len(levelNode)):
                posDict[levelNode[i]] = i
            for i in range(len(levelNode)):
                if(levelNode[i]!=levelNodeSort[i]):
                    replace = posDict[levelNodeSort[i]]
                    levelNode[replace] = levelNode[i]
                    posDict[levelNode[i]] = replace
                    levelNode[i] = levelNodeSort[i]
                    ans+=1

        return ans
                    