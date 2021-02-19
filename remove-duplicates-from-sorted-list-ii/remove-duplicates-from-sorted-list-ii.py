class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        st = set()
        lst = []
        while head:
            if head.val not in st:
                lst.append(head.val)
            elif head.val in st and head.val in lst:
                lst.remove(head.val)
            st.add(head.val)
            head = head.next
            
        ans = cur = ListNode(0)
        for num in lst:
            cur.next = ListNode(num)
            cur = cur.next
        return ans.next