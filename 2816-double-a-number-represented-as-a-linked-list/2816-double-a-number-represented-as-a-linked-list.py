# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = dummy = ListNode(0, head)
        while head:
            head.val *= 2
            prev.val += head.val // 10
            head.val %= 10
            prev, head = head, head.next
        return dummy if dummy.val else dummy.next
