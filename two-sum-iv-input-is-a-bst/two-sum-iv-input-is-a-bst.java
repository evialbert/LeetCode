/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {



    public boolean findTarget(TreeNode root, int k) {

        if(root==null)return false;

       List<Integer> ValList=new ArrayList<>();

        LDR(root,ValList);

        int x=0,y=ValList.size()-1;

        int sum=0;

        while(x<y){

            sum=ValList.get(x)+ValList.get(y);

            if(sum<k)x++;

            else if(sum>k)y--;

            else return true;

        }

        return false;

        

    }  

    public void LDR(TreeNode root,List<Integer> ValList){

        if(root==null) return ;

        LDR(root.left,ValList);

        ValList.add(root.val);

        LDR(root.right,ValList);      

    }

    

}