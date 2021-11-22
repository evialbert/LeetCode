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
    
    static int MOD = (int)(1e9 + 7);
    
    int nodesSum;
    long maximumProduct;
    public int maxProduct(TreeNode root) {
        
        //find all the node sum
        nodesSum = getAllNodeSum(root);
        
        maximumProduct = 0l;
        
        //find the max product
        findMaxProduct(root);
        
        return (int)(maximumProduct % MOD);
    }
    
    private int getAllNodeSum(TreeNode node){
        if(node == null) return 0;
        
        return getAllNodeSum(node.left) + getAllNodeSum(node.right) + node.val;
    }
    
    
    private int findMaxProduct(TreeNode node){
        if(node == null) return 0;
        
        int substree1Sum = findMaxProduct(node.left) + findMaxProduct(node.right) + node.val;
        
        
        //remaining node, will be subtree 2 sum
        int substree2Sum = nodesSum - substree1Sum;
        
        maximumProduct = Math.max(maximumProduct, (long)substree1Sum * substree2Sum);
        
        return substree1Sum;
    }
}