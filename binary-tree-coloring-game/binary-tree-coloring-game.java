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
   public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
        findX(root, x);
        parentCount = n - leftCount - rightCount - 1;
        return Math.max(parentCount, Math.max(leftCount, rightCount)) > n/2;
    }
    int leftCount;
    int rightCount;
    int parentCount;
    
    void findX(TreeNode root, int x) {
        if(root == null) return;
        if(root.val == x) {
            leftCount = count(root.left);
            rightCount = count(root.right);
            return;
        }
        
        findX(root.left, x);
        findX(root.right, x);
    }
    
    int count(TreeNode root) {
        if(root == null) return 0;
        int left = count(root.left);
        int right = count(root.right);
        return left + right + 1;
    }
}