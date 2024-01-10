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
    int max = 0;
    private void kLevelDown(TreeNode root,TreeNode blocker,int time){
        if(root==null || root==blocker){
            return ;
        }

        max = Math.max(max,time);
        kLevelDown(root.left,blocker,time+1);
        kLevelDown(root.right,blocker,time+1);
    }

    private int find(TreeNode root,int start){
        if(root==null){
            return -1;
        }

        if(root.val==start){
            kLevelDown(root,null,0);
            return 1;
        }

        int ld = find(root.left,start);
        if(ld!=-1){
            kLevelDown(root,root.left,ld);
            return ld+1;
        }
        int rd = find(root.right,start);
        if(rd!=-1){
            kLevelDown(root,root.right,rd);
            return rd+1;
        }

        return -1;
    }
    public int amountOfTime(TreeNode root, int start) {
        if(root==null){
            return 0;
        }

        find(root,start);
        return max;
        
    }
}