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
    
    public boolean f(TreeNode root,Set<Integer> st, List<TreeNode> lt){ 
        if(root==null) return false;
        
        if(f(root.left,st,lt))
            root.left=null;
        
        if(f(root.right,st,lt))
            root.right=null;
        
        if(st.contains(root.val)){ 
            if(root.left!=null) lt.add(root.left);
            if(root.right!=null) lt.add(root.right);
            return true;
        }
        return false;
    }
    public List<TreeNode> delNodes(TreeNode root, int[] nums) {
        List<TreeNode> lt=new LinkedList<>();
        Set<Integer> st=new HashSet<>();
        for(int e:nums) st.add(e);
        boolean vis=f(root,st,lt);
        if(!vis) lt.add(root);
        return lt;
    }
}