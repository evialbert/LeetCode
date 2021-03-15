/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        serializer(root, sb);
        return sb.toString();
    }
    public void serializer(TreeNode root, StringBuilder sb) {
        
        if(root == null)
            return ;
        sb.append(root.val).append(",");
        serializer(root.left, sb);
        serializer(root.right, sb);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data.isEmpty()) 
            return null;
        
        Queue<String> q= new LinkedList<>(Arrays.asList(data.split(",")));
        return deserializer(q, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }
    public TreeNode deserializer(Queue<String> q, int min, int max) {
        if (q.isEmpty()) 
            return null;
    
        String temp = q.peek();
        int x = Integer.parseInt(temp);
        if(x < min || x > max)
            return null;
        q.poll();
        TreeNode node = new TreeNode(x);
        node.left=deserializer(q, min, x);
        node.right=deserializer(q, x, max);
        
        return node;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// String tree = ser.serialize(root);
// TreeNode ans = deser.deserialize(tree);
// return ans;