# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        count_len, i, node = [0] * k, 0, head
        while node:
            count_len[i % k] += 1
            node = node.next
            i += 1

        ans = []
        for n in count_len:
            if n == 0:
                ans.append(None)
            else:
                ans.append(head)
                for _ in range(n):
                    prev = head
                    head = head.next
                prev.next = None
        return ans