# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if k==1 or head==None:
            return head
        i=1
        h=head
        while i<k:
            if h.next!=None:h=h.next
            else:return head
            i+=1
        endp=None
        while head!=None:
            phead=head
            i=1
            while i<k:
                if head.next!=None :
                    head=head.next
                else:
                    endp.next=phead
                    return h
                i+=1
            if endp!=None:endp.next=head
            head=phead
            endp=head
            pre=head
            head=head.next
            i=1
            while i<k:
                p=head
                head=p.next
                p.next=pre
                pre=p
                p=head
                i+=1
        endp.next=None
        return h