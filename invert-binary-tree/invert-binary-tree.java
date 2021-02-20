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
    public TreeNode invertTree(TreeNode root) {

        TreeNode tmp;

        if(root == null){

            return null;

        }

        tmp = root.right;

        root.right = root.left;

        root.left = tmp;

        if(root.left != null)

            invertTree(root.left);

        if(root.right != null)

            invertTree(root.right);

        return root;

    }
}