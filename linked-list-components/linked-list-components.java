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
    public int numComponents(ListNode head, int[] nums) {
        HashSet<Integer> set = new HashSet<Integer>();
        for(int i=0;i<nums.length;i++) set.add(nums[i]);
        
        ListNode n=head;
        while(n!=null){
            if(n.next!=null){
                int v=n.next.val;
                if(set.contains(v)){
                    set.remove(n.val);
                }
            }
            n=n.next;
        }
        return set.size();
    }
}