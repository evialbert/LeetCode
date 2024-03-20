# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        temp=list1
        for i in range(a-1):
            temp=temp.next
        temp2=temp
        n=b-a+2
        for i in range(n):
            temp2=temp2.next
        temp.next=list2
        while temp.next is not None:
            temp=temp.next
        temp.next=temp2
        return list1