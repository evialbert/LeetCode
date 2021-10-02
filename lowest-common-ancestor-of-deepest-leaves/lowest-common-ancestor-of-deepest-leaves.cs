/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
	public TreeNode LcaDeepestLeaves(TreeNode root) {
		HashSet<TreeNode> list = new HashSet<TreeNode>();
		Queue<TreeNode> queue = new Queue<TreeNode>();
		Dictionary<TreeNode, TreeNode> dict = new Dictionary<TreeNode, TreeNode>();

		queue.Enqueue(root);
		dict[root] = root;

		while(queue.Count > 0) {
			int size = queue.Count;
			list = new HashSet<TreeNode>();

			for(int i = 0; i < size; i++) {
				TreeNode node = queue.Dequeue();
				list.Add(node);

				if(node.left != null) {
					dict[node.left] = node;
					queue.Enqueue(node.left);
				}

				if(node.right != null) {
					dict[node.right] = node;
					queue.Enqueue(node.right);
				}
			}
		}

		while(list.Count > 1) {
			HashSet<TreeNode> parent = new HashSet<TreeNode>();
			foreach(var item in list)
				parent.Add(dict[item]);

			list = parent;
		}

		return list.First();
	}
}