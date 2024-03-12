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
    public ListNode removeZeroSumSublists(ListNode head) {
        HashMap<Integer,ListNode> map=new HashMap<>();
        ListNode dummy=new ListNode(0);
        dummy.next=head;
        map.put(0,dummy);
       int sum=0;
        for(ListNode i=dummy;i!=null;i=i.next){
            sum+=i.val;
            map.put(sum,i);
        }

        sum=0;
        for(ListNode i=dummy;i!=null;i=i.next){
            sum+=i.val;
            i.next=map.get(sum).next;
        }
        return dummy.next;
    }
}