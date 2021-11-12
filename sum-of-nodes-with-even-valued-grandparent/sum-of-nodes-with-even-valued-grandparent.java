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
    int tsum = 0;
    public int sumEvenGrandparent(TreeNode root) {
        solve(root);
        return tsum;
    }
    
    int sumOfChild(TreeNode node){
        if(node == null) return 0;
        
        int sum = 0;
        if(node.left != null) sum += node.left.val;
        if(node.right != null) sum += node.right.val;
        return sum;
    }
    
    void solve(TreeNode root){
        if(root == null) return;
        if(root.val % 2 == 0){
            tsum += sumOfChild(root.left);
            tsum += sumOfChild(root.right);
        }
        
        solve(root.left);
        solve(root.right);
        
    }
}