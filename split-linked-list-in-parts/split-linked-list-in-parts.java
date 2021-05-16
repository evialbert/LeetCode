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
    public ListNode[] splitListToParts(ListNode root, int k) {
        
		ListNode cnt = root;
		int len = 0;
		while (cnt != null) {
			len++;
			cnt = cnt.next;
		}
		ListNode[] res = new ListNode[k];
		cnt = root; 
		int carry = len % k;
	
		for (int i = 0; i < k && cnt != null; i++) {
			ListNode r = new ListNode(0);
			ListNode rr = r;
			int m = 0, j = 0;
			
			if (carry > 0) {
				j = 1;
				carry--;
			}
			while ((m++ < (len / k) + j) && cnt != null) {
				r.next = new ListNode(cnt.val);
				r = r.next; 
				cnt = cnt.next;
			}
			res[i] = rr.next;
		}

		return res;
    }
}