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
    public long kthLargestLevelSum(TreeNode root, int k) {
        PriorityQueue<Long> pq= new PriorityQueue<Long>();
        
        Queue<TreeNode> q= new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            long sum=0;
            int size= q.size();
            for(int i=0; i<size; i++){
                TreeNode cur= q.poll();
                sum+= cur.val;
                if(cur.left!=null){
                    q.add(cur.left);
                }
                if(cur.right!=null){
                    q.add(cur.right);
                }
            }
            pq.add(sum);
        }
        
        if(pq.size()<k){
            return -1;
        }
        
        while(pq.size()>k){
            pq.poll();
        }
        
        return pq.peek();
    }
}