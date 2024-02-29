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
    public boolean isEvenOddTree(TreeNode root) {
        Queue<TreeNode> qe = new LinkedList();   

        int flag=0;
        qe.add(root);

        while(!qe.isEmpty()){
            int s = qe.size();
            int evenLevelPre = -1;
            int oddLevelPre = 1000001;
            while(s>0){
                TreeNode curr = qe.remove();
                int x = curr.val;

                if(flag==0){
                    if(x%2==0) return false;
                    else{
                        if(x<=evenLevelPre) return false;
                        else{
                            evenLevelPre = x;
                            if(curr.left!=null) qe.add(curr.left);
                            if(curr.right!=null) qe.add(curr.right);
                        }
                    }
                }
                else{
                    if(x%2!=0) return false;
                    else{
                        if(x>=oddLevelPre) return false;
                        else{
                            oddLevelPre =x;
                            if(curr.left!=null) qe.add(curr.left);
                            if(curr.right!=null) qe.add(curr.right);
                        }
                    }
                }

                s--;
            }

            flag = Math.abs(flag-1);
        }

        return true;
    }
}