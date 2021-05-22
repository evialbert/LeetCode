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
    public class Pair{
        TreeNode t;
        int l,d;
        Pair(TreeNode t,int l,int d){
            this.t = t;
            this.l = l;
            this.d = d;
        }
    }
    public int widthOfBinaryTree(TreeNode root) {
        int res = 0;
        int start = 1, end = 1;
        ArrayDeque<Pair> q = new ArrayDeque<>();
        q.add(new Pair(root,0,1));
        int cl = 0;
        while(!q.isEmpty()){
            Pair er = q.removeFirst();
            if(cl != er.l){
                cl = er.l;
                res = Math.max(res,end-start);
                start = end = er.d;
            }
            else
                end = er.d;
            if(er.t.left != null)
                q.add(new Pair(er.t.left,er.l+1,2*er.d));
            if(er.t.right != null)
                q.add(new Pair(er.t.right,er.l+1,2*er.d+1));
        }
        res = Math.max(res,end - start);
        return res+1;
    }
}