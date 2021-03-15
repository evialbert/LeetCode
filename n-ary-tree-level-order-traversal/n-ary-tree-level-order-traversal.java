/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> res = new ArrayList();
        traverseNaryTree(root,0,res);
        
        return res;
    }
    
    public void traverseNaryTree(Node node, int level, List<List<Integer>> res){
        if(node==null) return;
        
        if(res.size()<=level) res.add(new ArrayList<Integer>());
        res.get(level).add(node.val);
        
        for(int i=0; i<node.children.size();i++) {
            traverseNaryTree(node.children.get(i), level+1, res);
        }
    }
}