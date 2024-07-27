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
    public ListNode modifiedList(int[] nums, ListNode head) {
        Set<Integer> list = new HashSet<>();
        for(int val:nums){
            list.add(val);
        }
         ListNode dummy=new ListNode(0);
           ListNode res=dummy;
           ListNode curr=head;
           while(curr!=null){
          int n=curr.val;
          if(!list.contains(n)){
            dummy.next=new ListNode(n);
            dummy=dummy.next;
          }

           curr=curr.next;

           }
           return res.next;
    }
}