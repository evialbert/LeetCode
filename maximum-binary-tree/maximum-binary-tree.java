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
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        int n = nums.length-1;
        return construct(nums,0,n);
    }
    
    private TreeNode construct(int arr[],int l, int r){
        if(l>r)
            return null;
        
        int ind = maxIndex(arr,l,r);
        TreeNode root = new TreeNode(arr[ind]);
        root.left = construct(arr,l,ind-1);
        root.right = construct(arr,ind+1,r);

        return root;
        
    }
    
    private int maxIndex(int nums[], int l, int r){
        int maxIndex = 0;
        int maxVal = Integer.MIN_VALUE;
        for(int i=l;i<=r;i++){
            if(nums[i]>maxVal){
                maxVal = nums[i];
                maxIndex = i;
            }
        }
        
        return maxIndex;
    }
}