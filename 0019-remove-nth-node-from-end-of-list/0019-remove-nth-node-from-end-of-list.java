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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode h1 = head;
        ListNode h2 = head;

        for(int i = 0; i<n; i++) {
            if(h2 != null) {
                h2 = h2.next;
            } else {
                break;
            }
        }

        if(h2 == null) {
            return h1.next;
        }

        while(h2.next != null) {
            h1 = h1.next;
            h2 = h2.next;
        }

        ListNode temp = h1.next.next;
        h1.next = temp;
        return head;
    }
}