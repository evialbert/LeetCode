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
public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
    ListNode l2 = list2;
    while(l2.next!=null) l2 = l2.next;
    
    ListNode nh = new ListNode(-1);
    nh.next = list1; 
    int count = 0;
    ListNode curr = nh;
    while(count!=a){
        count++;
        curr = curr.next;
    }
    ListNode temp = curr.next;
    curr.next = list2;
    curr = temp;
    
    while(count!=b){
        count++; 
        curr = curr.next;
    }
    l2.next = curr.next;
    
    return nh.next;
}
}