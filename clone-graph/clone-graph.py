"""
# Definition for a Node.
class Node(object):
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution(object):
    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """
        if not node:
            return None
        
        queue = collections.deque()
        queue.append(node)
        
        visited = {}
        rtn = Node(node.val, [])
        visited[node] = rtn
        
        while queue:
            curNode = queue.popleft()
            copyNode = visited[curNode]
            for n in curNode.neighbors:
                if n not in visited:
                    queue.append(n)
                    nNode = Node(n.val, [])
                    copyNode.neighbors.append(nNode)
                    visited[n] = nNode
                else:
                    nNode = visited[n]
                    if nNode not in copyNode.neighbors:
                        copyNode.neighbors.append(nNode)
        return rtn