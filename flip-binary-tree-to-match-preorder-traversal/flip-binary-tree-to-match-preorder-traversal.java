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
   public List<Integer> flipMatchVoyage(TreeNode root, int[] voyage) {
        List<Integer> result = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        int currIndex = 0;
        
        while(root!=null || !stack.isEmpty()) {
            while(root!=null) {
                if(root.val != voyage[currIndex++])
                    return Collections.singletonList(-1);
                
                if(currIndex < voyage.length && root.left != null && root.left.val != voyage[currIndex]) {
                    result.add(root.val);
                    TreeNode temp = root.left;
                    root.left = root.right;
                    root.right = temp;
                }
                
                stack.push(root);
                root = root.left;
            }
            
            root = stack.pop().right;
        }

        return result;
    }
}