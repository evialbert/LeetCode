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
    int count;
    public int goodNodes(TreeNode root) {
        return countNodes(root, root.val);
    }
    private int countNodes(TreeNode root, int max){
        if(root == null)    return count;
        if(root.val >= max){
            max = root.val;
            count++;
        }
        countNodes(root.left, max);
        countNodes(root.right, max);
        return count;
    }
}