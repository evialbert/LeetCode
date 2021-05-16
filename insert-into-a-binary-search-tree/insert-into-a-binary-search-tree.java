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
    public TreeNode insertIntoBST(TreeNode root, int val) {
        return put(root, val);
    }
    
    private TreeNode put(TreeNode node, int val) {
        if (node == null) return new TreeNode(val);
        if (node.val > val) node.left = put(node.left, val);
        else if (node.val < val) node.right = put(node.right, val);
        
        return node;        
    }
}