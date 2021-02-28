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
    public ListNode oddEvenList(ListNode head) {
        if(head==null) return head;
        ListNode head1=null;
        ListNode p1=head1;
        ListNode head2=null;
        ListNode p2=head2;
        int i=0;
        while(head!=null){
            if(i%2==0){
                if(p1==null){
                    head1=head;
                    p1=head;
                    
                }
                else{
                    p1.next=head;
                    p1=p1.next;
                }
            }else{
                if(p2==null){
                    head2=head;
                    p2=head;
                    
                }
                else{
                    p2.next=head;
                    p2=p2.next;
                }
            }
            head=head.next;
            i++;
        }
        p1.next=head2;
        if(p2!=null)
        p2.next=null;
        return head1;
    }
}