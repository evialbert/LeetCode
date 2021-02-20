/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        if (fast == null || fast.next == null) return true;
        while (fast.next != null && fast.next.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        ListNode newHead = reverseList(slow.next);
        while (newHead != null) {
            if (head.val != newHead.val) return false;
            head = head.next;
            newHead = newHead.next;
        }
        return true;
    }
	//Reverse linked list function -- see the previous article for details
    private ListNode reverseList(ListNode head) {
        if (head.next == null) return head;
        ListNode pre = null;
        ListNode tmp;
        while (head!= null) {
            tmp = head.next;//tmp stage the next node of the current node
            head.next = pre;//Current node next points to pre
            pre = head;//Refresh pre
            head = tmp;//Refresh the current node to tmp
        }
        return pre;
    }
}