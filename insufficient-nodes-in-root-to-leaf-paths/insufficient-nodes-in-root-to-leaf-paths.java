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
    
    //Returns whether the subtree rooted at current node should be pruned.
    boolean recurse(TreeNode node, int sum, int limit) {
        if (node == null)
            return true;
        
        sum += node.val;
        if (node.left == null && node.right == null)
            return sum < limit;
        
        boolean shouldPruneLeftChild = recurse(node.left, sum, limit), shouldPruneRightChild = recurse(node.right, sum, limit);
        
        //Prune children.
        node.left = shouldPruneLeftChild ? null : node.left;
        node.right = shouldPruneRightChild ? null : node.right;
        
        //If all children are pruned, then current node itself must be pruned.
        return shouldPruneLeftChild && shouldPruneRightChild;
    }
    
    public TreeNode sufficientSubset(TreeNode root, int limit) {
        boolean shouldPruneRoot = recurse(root, 0, limit);
        return shouldPruneRoot ? null : root;
    }
}