# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        p = q = head
        flag = 0
        
        while p and p.next:
            q = q.next
            
            p = p.next.next
        
            if p == q:
                flag = 1 
                break
                
        if flag == 0:
            return 
        
        q = head
        
        while q != p:
            q = q.next
            p = p.next
            
        return q