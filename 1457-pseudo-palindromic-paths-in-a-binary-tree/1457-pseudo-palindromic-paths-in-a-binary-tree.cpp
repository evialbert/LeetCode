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
    int pseudoPalindromicPaths (TreeNode* root) {
        
        return traverse(root,0);
    }

    int traverse(TreeNode* root,int flag)
    {
        if(root==NULL)
            return 0;
        flag = flag ^ (1<<root->val);
        if(root->left==NULL&&root->right==NULL)
        {
            if((flag & flag-1) == 0)
                return 1;
            return 0;
        }
        return traverse(root->left,flag) + traverse(root->right,flag);
        
    }
};