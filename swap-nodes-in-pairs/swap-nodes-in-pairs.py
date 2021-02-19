# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        ans = head.next
        t2 = head
        while(head and head.next):
            t1 = head.next
            t2.next = t1
            head.next = t1.next
            t1.next = head
            t2 = head
            head = head.next
        return ans