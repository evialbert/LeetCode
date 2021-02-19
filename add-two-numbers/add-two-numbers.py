# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        l3 = ListNode(0)
        l3.val = l1.val + l2.val + carry
        if l3.val >= 10:
            l3.val -= 10
            carry =1
        else:
            carry = 0
        a = l1.next
        b = l2.next
        c = l3
        while a and b:
            val = a.val + b.val + carry
            if val >= 10:
                val -= 10
                carry = 1
            else:
                carry = 0
            c.next = ListNode(val)    
            a = a.next
            b = b.next
            c = c.next
        
        if not a:
            a = b
        
        while a:
            val = a.val + carry
            if val >= 10:
                val -= 10
                carry = 1
            else:
                carry = 0
            c.next = ListNode(val)
            a = a.next
            c = c.next
            
        if carry:
            c.next = ListNode(1)
            
        return l3