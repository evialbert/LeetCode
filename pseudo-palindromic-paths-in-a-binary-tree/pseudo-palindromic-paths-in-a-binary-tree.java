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
    public int pseudoPalindromicPaths (TreeNode root) {
        return backtrack(root, 0);
    }

    private int backtrack(TreeNode root, int tmp){
        int sum = 0;
        tmp ^= 1 << root.val;
        if (root.right == null && root.left == null && (tmp & (tmp - 1)) == 0) sum = 1;
        if (root.right != null) sum += backtrack(root.right, tmp);
        if (root.left  != null) sum += backtrack(root.left , tmp);
        return sum;
    }
}