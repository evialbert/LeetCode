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
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer> a1 = new ArrayList<>();
        List<Integer> a2 = new ArrayList<>();
        dfs(root1, a1);
        dfs(root2, a2);
        a1.addAll(a2);
        Collections.sort(a1);
        return a1;
    }
    
    void dfs(TreeNode root, List<Integer> a){
        if(root == null) return;
        
        dfs(root.left, a);
        a.add(root.val);
        dfs(root.right, a);
    }
}