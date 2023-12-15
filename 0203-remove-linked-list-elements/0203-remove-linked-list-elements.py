# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:

        dummy = ListNode(next=head)
        prev, curr = dummy, head

        while curr:
            temp = curr.next
            if curr.val == val:
               prev.next = temp
            else:
                prev = curr
            curr = temp

        return dummy.next