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
    public int kthSmallest(TreeNode root, int k) {
        ArrayList<Integer> l = inorder(root, new ArrayList<Integer>());
        return l.get(k - 1);
    }
    
    public ArrayList<Integer> inorder(TreeNode root, ArrayList<Integer> l1) {
        if (root == null) return l1;
        inorder(root.left, l1);
        l1.add(root.val);
        inorder(root.right, l1);
        return l1;
    }
}