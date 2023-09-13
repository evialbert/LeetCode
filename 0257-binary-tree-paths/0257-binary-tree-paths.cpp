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
    bool isLeaf(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        return false;
    }
    void helper(TreeNode* root,vector<string>& ans,string s){
        if(root==NULL){
            return;
        }
        if(s.size()!=0) s=s+"->" + to_string(root->val);
        else s=s+ to_string(root->val);
        
        if(isLeaf(root)==true){
            ans.push_back(s);
            return;
        }
        helper(root->left,ans,s);
        helper(root->right,ans,s);
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s="";
        helper(root,ans,s);
        return ans;
    } 
};