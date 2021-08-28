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
    public TreeNode insertIntoMaxTree(TreeNode root, int val) {
        TreeNode node = new TreeNode(val);
        if(root == null) return node;
        if(val > root.val)
        {
            node.left = root;
            node.right = null;
            return node;
        }
        
        TreeNode current = root;
        while(current.right != null && current.right.val > val)
        {
            current = current.right;
        }
        //on exiting while loop, we either have current.right == null, or the right subtree
        //root value is less than val
        if(current.right == null)
        {
            current.right = node;
        }
        else
        {
            //current.right.val < val
            node.left = current.right;
            node.right = null;
            current.right = node;
        }
        return root;
    }
}