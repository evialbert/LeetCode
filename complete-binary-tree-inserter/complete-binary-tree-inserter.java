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
class CBTInserter {
    TreeNode root;
    Queue<TreeNode> queue = new LinkedList<>();
    public CBTInserter(TreeNode root) {
        this.root = root;        
        queue.offer(root);
    }
    
    public int insert(int v) {
        TreeNode node = new TreeNode(v);
        while(queue.peek().left != null && queue.peek().right != null) {
            TreeNode delete = queue.poll();
            queue.offer(delete.left);
            queue.offer(delete.right);
        }
        if(queue.peek().left == null) {
            queue.peek().left = node;
        } else {
           queue.peek().right = node; 
        }
        return queue.peek().val;
    }
    
    public TreeNode get_root() {
        return root;
    }
}
/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode param_2 = obj.get_root();
 */