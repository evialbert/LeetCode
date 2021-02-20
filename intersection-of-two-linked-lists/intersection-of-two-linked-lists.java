/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
   private int getLength(ListNode node) {
        int count = 0;
        while (node!= null) {
            node = node.next;
            count ++;
        }
        return count;
    }
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);
        ListNode longer = headA;
        ListNode shorter = headB;
        if (lengthA < lengthB) {
            longer = headB;
            shorter = headA;
        }
        int diff = Math.abs(lengthA - lengthB);
        for (int i = 0; i < diff; i ++) {
            longer = longer.next;
        }
        while (longer != shorter) {
            longer = longer.next;
            shorter = shorter.next;
        }
        return longer;
    }
}