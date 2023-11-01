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
    public int minimumOperations(TreeNode root) {
        int res=0;
        Queue <TreeNode> q=new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            int size=q.size();
            Map <Integer,Integer> mp= new TreeMap<>();
            List <Integer> list=new ArrayList<>();
            for(int i=0; i<size; i++){
                TreeNode node=q.poll();
                if(node.left!=null) q.add(node.left);
                if(node.right!=null) q.add(node.right);
                mp.put(node.val, i);
                list.add(node.val);
            }
            int index=0;
            for(int e: mp.keySet()){
                if(mp.get(e)==index) index++;
                else{
                    int i=mp.get(e);
                    int in= mp.get(list.get(i));
                    mp.put(list.get(index), i);
                    mp.put(e, index);
                    Collections.swap(list, index, in);
                    res++;
                    index++;
                }
            }
        }
        return res;
    }
}