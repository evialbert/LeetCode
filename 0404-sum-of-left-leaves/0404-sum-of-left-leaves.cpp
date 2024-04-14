/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	int ans = 0;
	TreeNode* prev = NULL;
	int sumOfLeftLeaves(TreeNode* root) {
		if(root == NULL)return 0;
		if(root->left){
			prev = root;
			sumOfLeftLeaves(root->left);
		}
		if(root->right){
			prev = root;
			sumOfLeftLeaves(root->right);
		}
		if(!root->left && !root->right){
			if(prev && prev->left == root)ans += root->val;
		}
		return ans;
	}
};