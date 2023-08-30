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
    TreeNode* DFS(TreeNode* root, int low, int high){
        if(root==NULL)
            return NULL;
        if(root->val >= low && root->val <= high){
            root->left=DFS(root->left,low,high);
            root->right=DFS(root->right,low ,high);
        }
        else if(root->val < low)
            return DFS(root->right,low,high);
        else
            return DFS(root->left,low ,high);
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return DFS(root,low,high);
    }
};