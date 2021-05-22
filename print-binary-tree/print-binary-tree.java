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
public List<List<String>> printTree(TreeNode root) {
    int h = height(root);
    Double sizeD = Math.pow(2.0,h*(1.0))-1.0;
    int size = sizeD.intValue();
    List<List<String>> result = new ArrayList<List<String>>();
    for(int i = 0; i < h; i++)
    {
        List<String> list = new ArrayList<>();
        result.add(list);
        for(int j = 0; j < size; j++)
        {
            list.add("");
        }
    }
    
    fillTree(root, result, 0, 0, size-1);
    return result;
}

void fillTree(TreeNode root, List<List<String>> result, int level, int start, int end)
{
    if(root == null)
    {
        return;
    }
    
    List<String> list = result.get(level);
    int val = root.val;
    
    int mid = start + (end-start)/2;
    list.set(mid, String.valueOf(val));
    fillTree(root.left, result, level+1, start, mid-1);
    fillTree(root.right, result, level+1, mid+1, end);
}

int height(TreeNode root)
{
    if(root == null)
    {
        return 0;
    }
    
    return 1 + Math.max(height(root.left),height(root.right));
}
}