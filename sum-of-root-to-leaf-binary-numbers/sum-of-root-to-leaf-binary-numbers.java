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
     public int sumRootToLeaf(TreeNode root) {
        List<String> list = new ArrayList<>();
        helper(list, root, new StringBuilder().append(Integer.toString(root.val)));
        int res = 0;
        for (String ele: list) {
            res += Integer.parseInt(ele, 2);
        }
        return res;
    }
    private void helper(List<String> list, TreeNode root, StringBuilder sb) {
        if (root == null) return;
        
        if (root.left == null && root.right == null) {
            list.add(sb.toString());
            return;
        }
        
        if (root.left != null) {
            sb.append(Integer.toString(root.left.val));
            helper(list, root.left, sb);
            sb.deleteCharAt(sb.length() - 1);
        }
        if (root.right != null) {
            sb.append(Integer.toString(root.right.val));
            helper(list, root.right, sb);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}