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
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
   public boolean isSubPath(ListNode head, TreeNode root) {
       ListNode curr = head;
       return traverse(root,head);
   }
   
   private boolean traverse(TreeNode root,ListNode head){
       if(root==null){
           return false;
       }
       boolean res = false;
       if(root.val==head.val){
           res = res || DFS(head,root);
       }
       return res || traverse(root.left,head) || traverse(root.right,head);
   }
   
   private boolean DFS(ListNode curr,TreeNode root) {
       if(root==null){
           return curr==null;
       }
       if(curr==null){
           return true;
       }
       if(curr.val!=root.val){
           return false;
       }
       return DFS(curr.next,root.left) || DFS(curr.next,root.right);
   }
}