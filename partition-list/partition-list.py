class Solution:
    # @param head, a ListNode
    # @param x, an integer
    # @return a ListNode
    def partition(self, head, x):
        if None == head or None == head.next:
            return head
        new_head = ListNode(-1)
        new_head.next = head
        tail = head
        while None != tail.next:
            tail = tail.next
        cur = head
        parent = new_head
        l_pos = new_head

        while tail != parent and None != cur:
            if cur.val >= x:
                break
            parent = parent.next
            cur =  cur.next
            l_pos = l_pos.next
        parent =  parent.next
        if None != cur:
            cur = cur.next
        #l_pos = l_pos.next

        while tail != parent and None != cur:
            if cur.val < x:
                parent.next = cur.next
                cur.next = l_pos.next
                l_pos.next = cur
                l_pos = l_pos.next
                cur = parent.next
            else:
                parent = parent.next
                cur =  cur.next
        return new_head.next