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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> res = new ArrayList<>();
        if(root == null) return res;
        helper(root, "", res);
        return res;
    }
    public void helper(TreeNode root, String s, List<String> res){
        if(root == null) return;
        if(root.left == null && root.right == null){
            res.add(s + root.val);
            return;
        }
        helper(root.left, s + root.val + "->", res);
        helper(root.right, s + root.val + "->", res);
    }
}