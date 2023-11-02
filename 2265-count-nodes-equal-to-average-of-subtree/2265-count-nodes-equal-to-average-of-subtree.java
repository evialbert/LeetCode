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
    int ans=0;
    public int averageOfSubtree(TreeNode root) {
        solveavg(root);
        return ans;
    }

    public int[] solveavg(TreeNode root)
    {
        	if(root==null)
            {
                return new int[]{0,0};
            }

            int[] left = solveavg(root.left);
            int[] right = solveavg(root.right);

            int sum_of = left[0]+right[0]+root.val;
            int no_of = left[1]+right[1]+1;
            if(sum_of/no_of == root.val)
            {
                ans++;
            }
            return new int[]{sum_of,no_of};
            
                }
}