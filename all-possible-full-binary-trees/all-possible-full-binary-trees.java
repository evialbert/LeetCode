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
    public List<TreeNode> allPossibleFBT(int n) {
        if(n % 2 == 0) return new ArrayList<>();
        else return solve(n);
    }
    
    public List<TreeNode> solve(int n) {
        if(n == 1) {
            List<TreeNode> l = new ArrayList<>();
            l.add(new TreeNode(0));
            return l;
        }
        List<TreeNode> curr = new ArrayList<>();
        for(int i = 1 ; i < n ; i+=2) {
            List<TreeNode> one = solve(i);
            List<TreeNode> two = solve(n-i-1);
            for(TreeNode left : one) {
                for(TreeNode right : two) {
                     TreeNode newN = new TreeNode(0 , left , right);
                     curr.add(newN);
                }
            }
        }
        return curr;
    }
}