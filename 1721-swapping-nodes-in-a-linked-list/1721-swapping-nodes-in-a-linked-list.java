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
    public ListNode swapNodes(ListNode head, int k) {
        ListNode temp=head;
        int i=1;
        while(i<k){
            temp=temp.next;
            i++;
        }
        System.out.println(temp.val);
        ListNode temp2=head;
        ListNode s=head;
        ListNode f=head;
        for(int j=1;j<=k;j++){
            f=f.next;
        }
        while(f!=null){
            s=s.next;
            f=f.next;
        }
        System.out.println(s.val);
        int hel=s.val;
        s.val=temp.val;
        temp.val=hel;
        return head;
    }
}