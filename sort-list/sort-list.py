# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
           return head
        List, cur = [], head
        while cur is not None:
            List.append(cur.val)
            cur = cur.next
        List = sorted(List)
        
        self.head = ListNode(List[0])
        cur = self.head
        for v in List[1:]:
            cur.next = ListNode(v)
            cur = cur.next
        return self.head

