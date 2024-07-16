# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        def getPath(node, target, dir_to_node):
            if node.val == target:
                return dir_to_node
            if node.left:
                ch_Path = getPath(node.left, target, "L")
                if ch_Path is not None:
                    return dir_to_node + ch_Path
            if node.right:
                ch_Path = getPath(node.right, target, "R")
                if ch_Path is not None:
                    return dir_to_node + ch_Path
            return None

        sPath, dPath = getPath(root, startValue, ""), getPath(root, destValue, "")
        common = 0
        while common < min(len(sPath),len(dPath)) and sPath[common] == dPath[common]:
            common += 1
        return "U"*(len(sPath)-common) + dPath[common:]

