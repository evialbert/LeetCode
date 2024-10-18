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
    // To store depths of perfect subtrees
    List<Integer> a = new ArrayList<>();

    public int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int left = dfs(root.left);
        int right = dfs(root.right);

        if (left == -1 || right == -1 || left != right) {
            return -1;
        }
        a.add(left + 1);
        return left + 1;
    }

    public int kthLargestPerfectSubtree(TreeNode root, int k) {
        dfs(root);
        Collections.sort(a, Collections.reverseOrder());
        if (a.size() < k) {
            return -1;
        }
        return (1 << a.get(k - 1)) - 1;
    }
}