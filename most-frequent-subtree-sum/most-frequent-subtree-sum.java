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
    private int maxFreq = 0;
    public int[] findFrequentTreeSum(TreeNode root) {
        if(root == null) {
            return new int[]{};
        }
        
        maxFreq = 0;
        Map<Integer, Integer> map = new HashMap<>();
        helper(root, map);
        
        List<Integer> list = new ArrayList<>();
        
        for(int i : map.keySet()) {
            if(map.get(i) == maxFreq) {
                list.add(i);
            }
        }
        
        int response[] = new int[list.size()];
        for(int i = 0; i < list.size(); i++) {
            response[i] = list.get(i);
        }
        
        return response;
    }
    
    private int helper(TreeNode node, Map<Integer, Integer> map) {
        if(node == null) {
            return 0;
        }
        
        int left = helper(node.left, map);
        int right = helper(node.right, map);
        
        int currSum = node.val + left + right;
        int freq = map.getOrDefault(currSum, 0);
        map.put(currSum, freq + 1);
        maxFreq = Math.max(freq + 1, maxFreq);
        
        return currSum;
    }
        
}