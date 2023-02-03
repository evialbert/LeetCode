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
		vector<int> v;
		void solve(TreeNode* root)
		{
			if(root == NULL)
			{
				return;
			}
			solve(root->left);
			v.push_back(root->val);
			solve(root->right);
		}
		bool findTarget(TreeNode* root, int k) {
			solve(root);
			int i = 0,j = v.size()-1;
			while(i < j)
			{
				int sum = v[i] + v[j];
				if(sum == k)
				{
					return true;
				}
				else if(sum < k)
				{
					i++;
				}
				else
				{
					j--;
				}
			}
			return false;
		}
	};