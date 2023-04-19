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
    int ans=0;
    void f(TreeNode* root,int cc,int dir)
    {
        if(root==nullptr)return ;
        ans = max(ans,cc);
        if(dir==0)
        {
            f(root->right,cc+1,1);
            f(root->left,1,0);
        }
        else
        {
            f(root->left,cc+1,0);
            f(root->right,1,1);
        }
    }
    int longestZigZag(TreeNode* root) {
      if(root==nullptr)return 0;
        f(root->left,1,0);
        f(root->right,1,1);
        return ans;
    }
};