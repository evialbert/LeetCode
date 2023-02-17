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
    void inorder(TreeNode* root,vector<int>&v){
        if(!root ) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
        
    }
    int minDiffInBST(TreeNode* root) {
        int ans=INT_MAX;
        if(!root) return ans;
        vector<int>v;
        inorder(root,v);
        for(int i=0;i<v.size()-1;i++){
            ans=min(ans,abs(v[i]-v[i+1]));
        }
        return ans;
    }
};