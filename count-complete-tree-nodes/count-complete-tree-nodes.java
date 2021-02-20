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
    int totDep;
    private int getTotalDepth(TreeNode root, int curDep) {
        return root.left == null ? curDep : getTotalDepth(root.left, curDep + 1);
    }
    private boolean hasHole(TreeNode root, int curDep) {
        return root.right == null ? curDep != totDep : hasHole(root.right, curDep + 1);
    }
    private int getNumHoles(TreeNode root, int curDep) {
        if(root.left == null) {
            return curDep == totDep ? 0 : 2;
        } else if(root.right == null) {
            return 1;
        } else if(hasHole(root.left, curDep + 1)) {
            return getNumHoles(root.left, curDep + 1) + (1 << (totDep - curDep - 1));
        } else {
            return getNumHoles(root.right, curDep + 1);
        }
    }
    public int countNodes(TreeNode root) {
        if(root == null) {
            return 0;
        }
        totDep = getTotalDepth(root, 0);
        return (1 << (totDep + 1)) - 1 - getNumHoles(root, 0);
    }
}