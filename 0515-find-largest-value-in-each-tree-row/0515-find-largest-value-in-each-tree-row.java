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

    private int max = -1;

    public List<Integer> largestValues(TreeNode root) {
        List<Integer> maxAtLevel = new ArrayList<>();
        doTraversal(root, maxAtLevel, -1);
        return maxAtLevel;
    }

    private void doTraversal(TreeNode root, List<Integer> maxAtLevel, int height) {
        height++;

        if(root == null) {
            return;
        }

        if(height > max) {
            maxAtLevel.add(root.val);
            max = height;
        } else {
            maxAtLevel.set(height, Math.max(root.val, maxAtLevel.get(height) ));
        }
        doTraversal(root.left, maxAtLevel, height);
        doTraversal(root.right, maxAtLevel, height);
    }
}