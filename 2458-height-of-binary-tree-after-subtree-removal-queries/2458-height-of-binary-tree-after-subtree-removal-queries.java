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
    int leftMax;
    int rightMax;
    // HashMap<Integer, Integer> allLevel;
    int[] allL;
    public int[] treeQueries(TreeNode root, int[] queries) {
        leftMax = 0;
        rightMax = 0;
        // allLevel = new HashMap<>();
        allL = new int[100001];
        int[] res = new int[queries.length];
        dfsLeft(root, 0);
        dfsRight(root, 0);
        for(int i = 0; i < queries.length; i++){
            res[i] = allL[queries[i]];
        }
        return res;
    }
    
    public void dfsLeft(TreeNode root, int level){
        if(root == null) return;
        allL[root.val] = leftMax;
        leftMax = Math.max(leftMax, level);
        dfsLeft(root.left, level + 1);
        dfsLeft(root.right, level + 1);
    }
    
     public void dfsRight(TreeNode root, int level){
        if(root == null) return;
        allL[root.val] = Math.max(rightMax, allL[root.val]);
        rightMax = Math.max(rightMax, level);
        dfsRight(root.right, level + 1);
        dfsRight(root.left, level + 1);
    }
}