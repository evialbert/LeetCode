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
    public TreeNode balanceBST(TreeNode root) {
        ArrayList<TreeNode> treeAsList = new ArrayList<>();
        walk(root, treeAsList);
        return buildTree(treeAsList, 0, treeAsList.size() - 1);
    }
    
    private void walk(TreeNode node, ArrayList<TreeNode> res) {
        if (node == null) return;
        
        walk(node.left, res);
        res.add(node);
        walk(node.right, res);
    }

    
    private TreeNode buildTree(ArrayList<TreeNode> treeAsList, int left, int right) {
        if (left > right) return null;
        
        int mid = left + (right - left) / 2;

		TreeNode node = treeAsList.get(mid);
        node.left = buildTree(treeAsList, left, mid - 1);
        node.right = buildTree(treeAsList, mid + 1, right);
        
        return node;
    }
}