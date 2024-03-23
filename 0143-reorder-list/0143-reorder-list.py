# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
	def reorderList(self, head: ListNode) -> None:
		if not head: return head
		slow, fast = head, head
		while fast.next and fast.next.next:
			slow = slow.next
			fast = fast.next.next
		
		prev, cur = None, slow.next
		while cur:
			save = cur.next
			cur.next = prev
			prev = cur
			cur = save
		slow.next = None
		
		head2 = prev
		while head2:
			save1 = head.next
			head.next = head2
			head = head2
			head2 = save1