# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        
        curNode=head.next
        curPrev=head
        while curNode:
            if curNode.val>=curPrev.val:
                curPrev=curNode
                curNode=curNode.next
            else:
                leftNode=head
                leftPrev=None
                curPrev.next=curNode.next
                while leftNode!=curNode:
                    if curNode.val<leftNode.val:
                        if leftNode==head:
                            curNode.next=leftNode
                            head=curNode
                        else:
                            curNode.next=leftNode
                            leftPrev.next=curNode
                        break                            
                    else:
                        leftPrev=leftNode
                        leftNode=leftNode.next
                        
                curNode=curPrev.next
        return head