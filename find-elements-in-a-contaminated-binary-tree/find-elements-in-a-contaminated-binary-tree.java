class FindElements {
    Set<Integer> set=new HashSet<>();
    public FindElements(TreeNode root) {
        //rcover
        root.val=0;
        set.add(0);
        dfs(root);
    }
    void dfs(TreeNode root){
        if(root==null) return;
        if(root.left!=null) root.left.val=2*root.val+1;
        if(root.right!=null) root.right.val=2*root.val+2;
        set.add(root.val);
        dfs(root.left);
        dfs(root.right);
    }
    public boolean find(int target) {
        return set.contains(target);
    }
}