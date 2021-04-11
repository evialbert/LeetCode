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
    public int findBottomLeftValue(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        int ans=root.val;
        while(!q.isEmpty()){
            int currQueueSize = q.size();
            for(int i=0;i<currQueueSize;++i){
                TreeNode front = q.poll();
                if(i==0) ans=front.val;
                if(front.left!=null) q.add(front.left);
                if(front.right!=null) q.add(front.right);
            }
        }
        return ans;
    }
}