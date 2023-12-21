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
    void recursion(TreeNode* root,string ds,vector<string>& ans){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            ds+=to_string(root->val);
            ans.push_back(ds);
            return;
        }
        ds+=to_string(root->val);
        ds+='-';
        ds+='>';
        recursion(root->left,ds,ans);
        recursion(root->right,ds,ans);
        return;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string ds ="";
        recursion(root,ds,ans);
        return ans;
        
    }
};