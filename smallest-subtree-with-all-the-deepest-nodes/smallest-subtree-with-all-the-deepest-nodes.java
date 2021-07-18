class Solution {
    int maxHeight;
    TreeNode result;
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        maxHeight = height(root);
        
        //traverse from the bottom up, comparing the heights of left and right to the maxHeight -> store root
        solve(root,0);
        
        return result;
    }
 
    public int solve(TreeNode root, int level)
    {
        if(root == null)
            return level;

        int left = solve(root.left,level+1);
        int right = solve(root.right,level+1);
        if(left == maxHeight && right == maxHeight)
        {
            result = root;  
        }
        return Math.max(left,right);
    }
    
    public int height(TreeNode root)
    {
        if(root == null)
            return 0;
        
        int left = height(root.left);
        int right = height(root.right);
        
        return Math.max(left,right) + 1;
    }
}