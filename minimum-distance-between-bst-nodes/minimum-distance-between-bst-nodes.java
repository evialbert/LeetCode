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
    private int ans;
    private int prev;
    private void dfs(TreeNode node){
        if(node != null){
            dfs(node.left);
            int newDist = node.val - prev;
            ans = this.ans < newDist ? ans : newDist;
            prev = node.val;
            dfs(node.right);
        }
    }
    
    public int minDiffInBST(TreeNode root) {
        ans = Integer.MAX_VALUE;
        prev = -9999;
        dfs(root);
        return ans;
    }
}