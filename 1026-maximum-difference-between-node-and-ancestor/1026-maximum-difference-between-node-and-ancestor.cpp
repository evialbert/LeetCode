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
    int solve(TreeNode* root,int m,int M){
        if(root==NULL)return 0;
        if(m==-1)m = root->val;
        if(M==-1)M = root->val;
        if(root->left==NULL && root->right==NULL){
            int x = m,X = M;
            if(x>root->val)x = root->val;
            if(X<root->val)X = root->val; 
            return X-x;
        }
        if(m>root->val){
            m = root->val;
        }
        if(M<root->val){
            M = root->val;
        }
        return max(solve(root->left,m,M),solve(root->right,m,M));
    }
    int maxAncestorDiff(TreeNode* root) {
        return solve(root,-1,-1);
    }
};