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
   public int deepestLeavesSum(TreeNode root) {
    int sum=0;
    if(root==null)return sum;
    Queue<TreeNode> q=new LinkedList<>();
    q.add(root);
    
    while(!q.isEmpty())
    {
        sum=0;
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            TreeNode temp=q.peek();
            
            if(temp.left!=null)
                q.add(temp.left);
            if(temp.right!=null)
                q.add(temp.right);
            
            sum=sum+temp.val;
            q.remove();
        }
    }
    return sum;
}
}