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
    public ListNode sortList(ListNode head) {
        if(head == null){
            return head;
        }

        int length = 0, index = -1;
        ListNode temp = head;

        while(temp != null){
            length++;
            temp = temp.next;
        }

        int arr[] = new int[length];
        temp = head;

        while(temp != null){
            arr[++index] = temp.val;
            temp = temp.next;
        }

        Arrays.sort(arr);
        temp = head;
        index = -1;

        while(temp != null){
            temp.val = arr[++index];
            temp = temp.next;
        }

        return head;
    }
}