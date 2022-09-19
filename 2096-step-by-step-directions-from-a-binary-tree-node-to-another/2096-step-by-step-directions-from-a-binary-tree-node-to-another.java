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
    public String getDirections(TreeNode root, int startValue, int destValue) {
        StringBuilder start=new StringBuilder();
        StringBuilder dest=new StringBuilder();
        boolean check=recursion(root,startValue,start);
        
        boolean check1=recursion(root,destValue,dest);
        
        int idx=0;
        while(idx<start.length() && idx<dest.length() && start.charAt(idx)==dest.charAt(idx))
        idx++;
        
        StringBuilder ans=new StringBuilder();
        for(int i=idx;i<start.length();i++)
        ans.append('U');
        
        ans.append(dest.substring(idx));
        return ans.toString();
    }
    private boolean recursion(TreeNode root,int value,StringBuilder sb)
    {
        if(root==null)
        return false;
        if(root.val==value)
        return true;
        sb.append('L');
        if(recursion(root.left,value,sb))
        return true;
        sb.deleteCharAt(sb.length()-1);
        sb.append('R');
        if(recursion(root.right,value,sb))
        return true;
        sb.deleteCharAt(sb.length()-1);
        
        return false;
    }
}