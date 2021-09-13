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
    public TreeNode recoverFromPreorder(String s) {
        Stack<TreeNode> st=new Stack<>();
        
        if(s.length()==0){
            return new TreeNode();
        }
    
        
        for(int i=0;i<s.length();){
            int level=0;
            while(i<s.length() && s.charAt(i)=='-'){
               level++;
                i++;
            }
            
             while(st.size()>level){
                st.pop();
            }
            
            String temp="";
            while(i<s.length() && s.charAt(i)!='-'){
                temp+=s.charAt(i);
                i++;
            }
            int value=Integer.parseInt(temp);           
            TreeNode t=new TreeNode(value);
            if(st.size()!=0){
                if(st.peek().left==null)
                    st.peek().left=t;
                else
                    st.peek().right=t;
            }
            st.add(t);
        }
        while(st.size()>1)
            st.pop();
        return st.pop();
    }
}