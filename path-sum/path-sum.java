/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
     if(root == null){
        return false;
    }
    if(root.right == null && root.left == null && sum == root.val){
        return true;
    }
    boolean left = hasPathSum(root.left,sum-root.val);
    boolean right = hasPathSum(root.right,sum-root.val);
    return left || right;   
    }
}