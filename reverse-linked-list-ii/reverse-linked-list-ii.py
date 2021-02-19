class Solution:

    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:

        if not head or not head.next:

            return head

        dummy = ListNode(None)

        dummy.next = head

        prev = dummy

        curr = head

        while curr and m > 1:

            prev = curr

            curr = curr.next

            m -= 1

            n -= 1

        start_prev = prev

        start_curr = curr

        while curr and n > 0:

            temp = curr.next

            curr.next = prev

            prev = curr

            curr = temp

            n -= 1

            

        start_prev.next = prev

        if start_curr:

            start_curr.next = curr

        return dummy.next