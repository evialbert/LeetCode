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
   Map<String,Integer> mp=new HashMap<>();
   List<TreeNode> res=new ArrayList<>();
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        helper(root);
      return res;
    }
    private String helper(TreeNode node){
      if(node==null) return "*";
      
      String ls=helper(node.left);
      String rs=helper(node.right);
      String checkDuplicate=node.val+"-"+ls+"-"+rs;
      mp.put(checkDuplicate,mp.getOrDefault(checkDuplicate,0)+1);
      //check the corresponding key in Map whether its values equals to 2
      if(mp.get(checkDuplicate)==2) res.add(node);
      
      return checkDuplicate;
    }
}