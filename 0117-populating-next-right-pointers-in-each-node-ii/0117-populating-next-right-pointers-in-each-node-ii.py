class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root==None:return None
        tree=[root]
        child=[]

        while len(tree)>0:
            helper=[]
            while len(tree)>0:
                head=tree.pop(0)
                if head.left:
                    helper.append(head.left)
                    child.append(head.left)
                if head.right:
                    helper.append(head.right)
                    child.append(head.right)
            
            for i in range(len(child)-1):
                child[i].next=child[i+1]
            
            child=[]
            tree=helper
        
        return root
