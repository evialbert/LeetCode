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
    
    public ListNode reverseBetween(ListNode head, int left, int right) {
        
        
        int m = left, n = right;
        
        /*  Corner Case */
        
        if (head == null || head.next == null || m <= 0 || n <= 0 || m == n) {
            return head;
        }
        
        // to store the head index, to return the final updated head at this index.
        
        ListNode preHead = new ListNode(0);  
        preHead.next = head;
        
        // Traverse the list till position m. Position m -> index m-1 => loop till 0 to m-2.
        
        ListNode prev = preHead;
        
        for (int i = 0; i <= m-2; i++) {
            prev = prev.next;
        }
        
        // Reverse the list from position m to n.
        
        ListNode curr = prev.next;
        ListNode temp = null;
        
        ListNode reverseHead = null;
        
        for (int i = 0; i <= n-m; i++) {
            
            temp = curr.next;         // save next of current for next iteration
            curr.next = reverseHead;  // reset current to point back not forward
            
            reverseHead = curr;       // make current as head of new reverseHead list
            curr = temp;              // move to next node
            
        }
        
        
        // Connect the reversed list with the prev node (position m-1)
        
        prev.next.next = curr;
        prev.next = reverseHead;
        
     
    return preHead.next;
        
        
    }
}