# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        double_move, rev = head, None
        while double_move:
            single_move = head.next
            if double_move := double_move.next:
                double_move = double_move.next
                head.next = rev
                rev = head

            head = single_move

        while head and head.val == rev.val:
            rev, head = rev.next, head.next

        return not head
