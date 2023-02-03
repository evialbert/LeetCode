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
   void inorder(TreeNode* root,vector<int> &res)
   {
       if(root==NULL)
           return;
       inorder(root->left,res);
       res.push_back(root->val);
       inorder(root->right,res);
   }
    bool isValidBST(TreeNode* root) {
        vector<int>res;
        inorder(root,res);
        bool k=true;
        for(int i=0;i<res.size()-1;i++)
        {
            if(res[i]>=res[i+1])
                k=false;
        }
        return k;
    }
};