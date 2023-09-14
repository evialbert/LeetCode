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
    public int rob(TreeNode root) {
        Pair<Integer, Integer> ans = helper(root);
        return Math.max(ans.getKey(), ans.getValue());
    }

    Pair<Integer, Integer> helper(TreeNode node) {
        if (node == null) {
            return new Pair<>(0, 0);
        }

        Pair<Integer, Integer> l = helper(node.left);
        Pair<Integer, Integer> r = helper(node.right);
        int a = node.val + l.getValue() + r.getValue();
        int b = Math.max(l.getKey(), l.getValue()) +  Math.max(r.getKey(), r.getValue());
        return new Pair<>(a, b);
    }
}