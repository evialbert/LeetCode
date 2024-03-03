# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        l=[]
        i=head
        while i:
            l.append(i.val)
            i=i.next
        l.pop(-n)
        def lst2lnk(l):
            cur=head=ListNode(0)
            for i in l:
                cur.next=ListNode(i)
                cur=cur.next
            return head.next
        return lst2lnk(l)