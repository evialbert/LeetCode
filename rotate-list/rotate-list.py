class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head or not head.next or k==0:
            return head
        slow=head
        fast=head 
        count=0
        flag=0
        while fast and fast.next:
            count+=1
            slow=slow.next
            if not fast.next.next:
                fast=fast.next
                flag=1
                break 
            else:
                fast=fast.next.next 
        if flag==1:
            l = 2*count 
        else:
            l=2*count+1
        p=head 
        step=(l-k%l)%l
        if step==0:
            return head
        while step>0:
            step-=1
            q=p
            p=p.next
        q.next=None    
        fast.next=head
        return p