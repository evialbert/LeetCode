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
	int[] pre;
	int[] post;

	int preIndex;

	Map<Integer, Integer> postIndexMap;

	public TreeNode constructFromPrePost(int[] pre, int[] post) {

		int n = pre.length;

		// Initialize
		this.pre = pre;
		this.preIndex = 0;
		this.postIndexMap = new HashMap<Integer, Integer>();

		for (int i = 0; i < n; i++)
		   this.postIndexMap.put(post[i],i);

		return helper(0, n - 1);
	}

	private TreeNode helper(int left, int right) {

		if (preIndex == pre.length || left > right) return null;

		int val = pre[preIndex];
		int postIndex = postIndexMap.get(val);

		if (postIndex < left || postIndex > right)
			return null;

		preIndex++;
		TreeNode node = new TreeNode(val);
		node.left = helper(left, postIndex - 1);
		node.right = helper(left, postIndex - 1);

		return node;
	}
}