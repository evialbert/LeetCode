"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if head is None:
            return None
        
        nodeDict = dict()
        
        # First loop to copy all node
        pointer = head
        while pointer:
            nodeDict[pointer] = Node(pointer.val, None, None)
            pointer = pointer.next
        
        # Second loop to copy relationship
        pointer = head
        while pointer:
            if pointer.next:
                nodeDict[pointer].next = nodeDict[pointer.next]
            if pointer.random:
                nodeDict[pointer].random = nodeDict[pointer.random]
            pointer = pointer.next
        
        return nodeDict[head]