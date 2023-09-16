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
    void dfs(TreeNode* &root, unordered_set<int> &s, vector<TreeNode*> &ans) {
        if(!root) return;
        
        dfs(root -> left, s, ans);
        dfs(root -> right, s, ans);
        
        if(s.find(root -> val) != s.end()) {
            if(root -> left) ans.push_back(root -> left);
            if(root -> right) ans.push_back(root -> right);
            
            root = NULL;
            delete root;
        }
    }
    
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> s;
        s.insert(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;
        
        dfs(root, s, ans);
        if(root) ans.push_back(root);
        
        return ans;
    }
};