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

     pair<int,int> sum(TreeNode* root)
    {
        if(root==NULL)
        {
            return make_pair(0,0);
        }
        pair<int,int> p=sum(root->left);
        pair<int,int> q=sum(root->right);
        return make_pair(max(p.second,p.first)+max(q.first,q.second),root->val+p.first+q.first);
    }

    int rob(TreeNode* root) {
        pair<int,int> p=sum(root);
        return max(p.first,p.second);
    }
};