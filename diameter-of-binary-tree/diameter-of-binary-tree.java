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
    private int ans = 1;
    private int dfs(TreeNode node){
        if(node==null){ return 0; }
        int left = dfs(node.left);
        int right = dfs(node.right);
        int temp = left + right + 1;
        ans = temp > ans ? temp : ans;
        int depth = left > right ? left : right;
        return depth + 1;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        dfs(root);
        return ans-1;
    }
}