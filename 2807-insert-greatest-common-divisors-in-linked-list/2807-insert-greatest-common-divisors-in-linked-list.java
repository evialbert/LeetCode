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
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        ListNode curr = head;
        ListNode prev = null;
        while(curr.next != null) {
            prev = curr;
            curr = curr.next;
            ListNode temp = new ListNode(gcd(prev.val, curr.val));
            temp.next = prev.next;
            prev.next = temp;
        }
        return head;
    }

    int gcd(int x, int y) {
        int greater = x > y ? x : y;
        int smaller = x < y ? x : y;
        int res = smaller;
        while(greater % smaller != 0) {
            res = greater % smaller;
            greater = smaller;
            smaller = res;
        }
        return res;
    }
}