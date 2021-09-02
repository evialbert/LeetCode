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

/*

[8,5,1,7,10,12]

child = 12
parent = 10
stack = 10
Tree      
        8
      5   10
     1 7    12
     

*/
class Solution {
    public TreeNode bstFromPreorder(int[] preorder) {
                
        TreeNode root = new TreeNode(preorder[0]);
        Deque<TreeNode> stack = new ArrayDeque<>();
        stack.push(root);
        
        for(int i=1;i<preorder.length;i++)
        {
            TreeNode child = new TreeNode(preorder[i]);
            TreeNode parent = stack.peek();
            
            while(!stack.isEmpty() && stack.peek().val < child.val)
                parent = stack.pop();
            
            if(child.val < parent.val)
                parent.left = child;
            else 
                parent.right = child;
            
            stack.push(child);
        }
        
        return root;
    }
}