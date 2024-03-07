# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
   def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
       if head is None or head.next is None:
           return head
       slow, fast = head.next, head.next.next
       while fast and fast.next:
           slow = slow.next
           fast = fast.next.next
       return slow