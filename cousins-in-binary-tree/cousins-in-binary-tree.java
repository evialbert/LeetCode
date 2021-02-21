/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isCousins(TreeNode root, int x, int y) {
        if (root == null) {
            return false;
        }

        HashMap<Integer, Integer> valParentMap = new HashMap<>();

        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);

        while(!queue.isEmpty()) {
            int size = queue.size();

            List<Integer> list = new ArrayList<>();

            for (int i = 0; i < size; i++) {
                TreeNode node = queue.remove();
                list.add(node.val);

                if (node.left != null) {
                    queue.add(node.left);
                    valParentMap.put(node.left.val, node.val);
                }

                if (node.right != null) {
                    queue.add(node.right);
                    valParentMap.put(node.right.val, node.val);
                }
            }

            if (list.containsAll(Arrays.asList(x, y)) && !valParentMap.get(x).equals(valParentMap.get(y))) {
                return true;
            }
        }
        return false;
    }
}