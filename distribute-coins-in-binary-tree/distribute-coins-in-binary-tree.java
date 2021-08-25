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
    int moves=0;
    public int distributeCoins(TreeNode root) {
        dis(root);
        return moves;
    }
    private int dis(TreeNode node){
      if(node==null) return 0;
      int l=dis(node.left);
      int r=dis(node.right);
      moves=moves+Math.abs(l)+Math.abs(r);
      return node.val+l+r-1;
        
    }
}