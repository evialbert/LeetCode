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
    private int sum = 0;
    public int sumOfLeftLeaves(TreeNode root) {
        helper(root, false);
        return sum;
    }

    private void helper(TreeNode root, boolean isLeft){
        if(root == null) return;
        if(root.left == null && root.right == null){
            if(isLeft) sum += root.val;
            return;
        }
        
        helper(root.left, true);
        helper(root.right, false);       
    }
}