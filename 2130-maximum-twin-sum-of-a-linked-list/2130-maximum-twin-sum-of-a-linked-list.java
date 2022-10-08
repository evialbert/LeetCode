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
    public ListNode reverse(ListNode node)
    {
        ListNode prev = null;
        ListNode current = node;
        ListNode next = null;
        while (current != null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        node = prev;
        return node;
    }
    public int pairSum(ListNode head) {
        int length=0;
        ListNode temp=head;
        while(temp!=null){
            temp=temp.next;
            length++;
        }
        int pos=length/2;
        int i=0;
        temp=head;
        while(i<pos){
            temp=temp.next;
            i++;
        }
        ListNode head1=reverse(temp);
        int max=0;
        while(head!=null && head1!=null){
            int val=head.val+head1.val;
            if(val>max)  max=val; 
            head=head.next;
            head1=head1.next;
        }
        return max;
    }
}