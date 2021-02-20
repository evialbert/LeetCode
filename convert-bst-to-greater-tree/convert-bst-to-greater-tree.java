/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {

    int cusum = 0;

    public TreeNode convertBST(TreeNode root) {

        if (root == null) return root;

        convertBST(root.right);

        root.val += cusum;

        cusum = root.val;

        convertBST(root.left);

        return root;

    }

}