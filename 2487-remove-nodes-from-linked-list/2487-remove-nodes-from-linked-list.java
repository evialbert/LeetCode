/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNodes(ListNode head) {
        if(head.next == null) {
            return head;
        }

        ListNode prev = null;
        ListNode curr = head;

        while (curr != null) {
            ListNode temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
        }

        head = prev;
        curr = head.next;

        while (curr != null) {
            if (curr.val < prev.val) {
                curr = curr.next;
            }else{
                ListNode temp = curr.next;
                curr.next = prev;
                prev = curr;
                curr = temp;
            }
        }

        head.next = null;
        head = prev;
        return head;
    }
}