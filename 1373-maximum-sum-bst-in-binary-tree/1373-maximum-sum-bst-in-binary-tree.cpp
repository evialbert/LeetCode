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
class BST{
public :
	long long int mini;  /// minimum till that node subtree
	long long int maxi;  /// maximum till that node subtree
	bool bst;            /// is that node binary search tree
	long long int sum;   /// sum of nodes value till that node (or sum of that node + sum of it's subtree value's)
};

class Solution {
public:

	BST maxSumBST_helper(TreeNode* root , long long int& maxSum){
		BST curr;
		
		/// base case
		if(root == NULL){
		   curr.mini = INT_MAX;
		   curr.maxi = INT_MIN;
		   curr.bst = true;
		   curr.sum = 0;
		   return curr;
		}

       /// call node's left subtree and right subtree
		BST leftTree  = maxSumBST_helper(root -> left  , maxSum);
		BST rightTree = maxSumBST_helper(root -> right , maxSum);

        /// to check binary search tree
		curr.mini = min({1ll * root -> val , leftTree.mini , rightTree.mini});
		curr.maxi = max({1ll * root -> val , leftTree.maxi , rightTree.maxi});
		curr.bst = (leftTree.bst && rightTree.bst && root -> val > leftTree.maxi && root -> val < rightTree.mini);

       /// calculate sum of nodes in the subtree + node's value
		curr.sum = rightTree.sum + leftTree.sum + root -> val;
		if(curr.bst){
		  /// if bst , then find global optimum answer
		   maxSum = max(curr.sum , maxSum); 
		}
		return curr;
	}

	int maxSumBST(TreeNode* root) {
		long long int maxSum = 0;
		maxSumBST_helper(root , maxSum);
		return maxSum;
	}
};