/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode fakeHead = new ListNode(-1);
        ListNode node = head;
        while (node != null){
            ListNode nodeNext = node.next;
            node.next = fakeHead.next;
            fakeHead.next = node;
            node = nodeNext;
        }
        return fakeHead.next;
    }
}