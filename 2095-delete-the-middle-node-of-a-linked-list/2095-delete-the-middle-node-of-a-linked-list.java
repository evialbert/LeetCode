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
    public ListNode deleteMiddle(ListNode head) {
        int count=0;
        if (head == null || head.next == null) 
            return null;
        ListNode temp = head;
        while(temp!=null){
            temp=temp.next;
            count++;
        }
        int mid=count/2;
        ListNode prev = head;
        temp=head;
        while(temp!=null && mid>0){
             mid--;
             prev=temp;
             temp=temp.next;
        }
        prev.next=temp.next;
        return head;
    }
}