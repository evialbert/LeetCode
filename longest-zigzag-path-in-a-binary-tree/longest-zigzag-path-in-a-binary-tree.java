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
    int maxPath = 0;
    
    public int longestZigZag(TreeNode root) {
        if (root != null) {
            dfs(root);
        }
        return maxPath;
    }
    
    private int[] dfs(TreeNode root) {
        int left = 0; //left zigzag path
        if (root.left != null) {
            int[] leftArr = dfs(root.left); 
            left = leftArr[1] + 1; //left child's right zigzag path + 1
        }
        
        int right = 0; //right zigzag path
        if (root.right != null) {
            int[] rightArr = dfs(root.right);
            right = rightArr[0] + 1; //right child's left zigzag path + 1
        }
        
        int[] result = new int[2];
        result[0] = left;
        result[1] = right;
        
        maxPath = Math.max(maxPath, Math.max(left, right));
        
        return result;
    } 
    
}