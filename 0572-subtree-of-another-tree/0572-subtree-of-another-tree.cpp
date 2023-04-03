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

	bool isSame(TreeNode* p, TreeNode* q){

		if(p == NULL || q == NULL){
			return (p == q);
		}    
		return (p->val == q->val) && isSame(p->left, q->left) && isSame(p->right, q->right);
	}


	bool isSubtree(TreeNode* root, TreeNode* subRoot) {

		if(root == NULL){
			return false;
		}

		if(subRoot == NULL){ 
			return true;
		}

		if(isSame(root, subRoot)){
			return true;
		}

		return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
	}
};