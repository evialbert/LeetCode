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
    public TreeNode replaceValueInTree(TreeNode root) {
        Deque<Node> queue = new ArrayDeque<>();
        int prevTotalSum=root.val;
        queue.add(new Node(root, root.val));

        while(!queue.isEmpty()){
            int size=queue.size();
            int totalSum=0;

            for(int i=0;i<size;i++){
                Node qNode = queue.poll();
                TreeNode node = qNode.node;
                int siblingSum = qNode.siblingSum;

                int sum=node.left!=null?node.left.val:0;
                sum+=node.right!=null?node.right.val:0;

                if(node.left!=null) queue.add(new Node(node.left, sum));
                if(node.right!=null) queue.add(new Node(node.right, sum));

                totalSum+=sum;
                node.val = prevTotalSum-siblingSum;
            }
            prevTotalSum=totalSum;
        }

        return root;
    }

    class Node{
        TreeNode node;
        int siblingSum;

        Node(TreeNode node, int siblingSum){
            this.node=node;
            this.siblingSum=siblingSum;
        }
    }
}