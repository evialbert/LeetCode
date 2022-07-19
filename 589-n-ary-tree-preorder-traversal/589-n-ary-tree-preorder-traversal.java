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
    public List<Integer> preorder(Node root) {
        List<Integer> res = new LinkedList<>();
        return traverse(root, res);
    }
    
    public List<Integer> traverse(Node root, List<Integer> res){
        if(root==null) return res;
        res.add(root.val);
        // traverse all of its children's
        for(int i=0;i<root.children.size();i++){
            traverse(root.children.get(i), res);
        }
        return res;
    }
}