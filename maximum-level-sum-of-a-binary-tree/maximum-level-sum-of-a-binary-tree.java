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
    public int maxLevelSum(TreeNode root) {
        int maxSum = Integer.MIN_VALUE;
        int curLevel = 0;
        int minLevel = 0;
        if(root == null){ return maxSum;}
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.add(root);
        while(!queue.isEmpty()){
            int size = queue.size();
            int sumPerLevel = 0;
            curLevel++;
            for(int i=0;i<size; i++){
                TreeNode cur = queue.poll();
                sumPerLevel += cur.val;
                if(cur.left != null) queue.add(cur.left);
                if(cur.right != null) queue.add(cur.right);
            }
            if(maxSum<sumPerLevel){
                maxSum = sumPerLevel;
                minLevel = curLevel;
            }
        }
        return minLevel;
    }
}