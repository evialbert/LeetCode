/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
public ListNode middleNode(ListNode head) {

	ListNode fast = head;

	while(fast != null && fast.next != null){

		fast = fast.next.next;
		head = head.next;    
	}
	return head;
}
}