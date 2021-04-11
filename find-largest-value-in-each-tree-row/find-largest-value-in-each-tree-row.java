class Solution {
    void inorder(TreeNode root, int count, List<Integer> res) {
        if(root == null) return;
        if(res.size() == count) {
            res.add(root.val);
        } else {
            res.set(count, Math.max(res.get(count),root.val));
        }
        inorder(root.left, count+1, res);
        inorder(root.right, count+1, res);
    }
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        inorder(root,0,res);
        return res;
    }
}