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
    public int maxAncestorDiff(TreeNode root) {
        int[] maxDiff = new int[1];
        traverseAndCalculateMaxDiff(root, root.val, root.val, maxDiff);
        return maxDiff[0]; // max absolute diff
    }
    
	// each time we need to pass the min and max on path. their difference will give max abs difference
    private void traverseAndCalculateMaxDiff(TreeNode node, int min, int max, int[] maxDiff) {
        if (node != null) {
            min = node.val < min ? node.val : min;
            max = node.val > max ? node.val : max;
            if (maxDiff[0] < max - min) {
                maxDiff[0] = max - min;
            }
            traverseAndCalculateMaxDiff(node.left, min, max, maxDiff);
            traverseAndCalculateMaxDiff(node.right, min, max, maxDiff);
        }
    }
}