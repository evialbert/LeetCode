class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        TreeNode parent = null;
        TreeNode cur = root;
        Integer min = null;
        if(root == null) return null;
        if(root.val > key) root.left = deleteNode(root.left, key);
        else if(root.val < key) root.right = deleteNode(root.right, key);
        else{
            parent = root;
            if(root.left == null){
                return deleteNode(root.right, key); 
            }
            if(root.right == null){
                return deleteNode(root.left, key);
            }
            
            if(root.right != null && root.left != null){
                root.val = minValue(root.right);
                root.right = deleteNode(root.right, root.val);
            }
        }
        return root;
    }
    public int minValue(TreeNode node){
        int min = node.val;
        while(node.left != null){
           min = node.left.val;
           node = node.left;
        }
        return min;
    }
}