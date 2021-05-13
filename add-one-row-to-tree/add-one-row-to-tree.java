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
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if(root==null)
            return null;
        
        if(depth==1)
        {
            TreeNode naya   = new TreeNode(val);
            naya.left=root;
            return naya;
        }
        else if(depth ==2)
        {
            TreeNode nayaLeft  = new TreeNode(val);
            TreeNode nayaRight  = new TreeNode(val);
            nayaLeft.left = root.left;
            nayaRight.right = root.right;
            root.left = nayaLeft;
            root.right = nayaRight;
            return root;
        }
        addOneRow(root.left, val, depth-1);
        addOneRow(root.right, val, depth-1);
        return root;
        
    }
}