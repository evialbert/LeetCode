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
    int count=0;
    List<Integer>find(TreeNode root,int distances){
        List<Integer>list=new ArrayList<>();
        if(root==null)return list;
        if(root.left==null && root.right==null){list.add(0);return list;}
        List<Integer>left=find(root.left,distances);
        List<Integer>right=find(root.right,distances);
        for(int l : left)
            for(int r : right) if(l+r+2<=distances)count++;
        for(int l : left)if(l+1<distances)list.add(l+1);
        for(int r : right)if(r+1<distances)list.add(r+1);
        return list;
    }
    public int countPairs(TreeNode root, int distance) {
        find(root,distance);
        return count;
    }
}