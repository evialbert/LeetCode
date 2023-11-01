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
    unordered_map<int, int> mp;
    
    void inorder(TreeNode* root) {
        if (root->left) inorder(root->left);
        mp[root->val]++;
        if (root->right) inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        int mx = 0;
        for (auto& x : mp) mx = max(mx, x.second);
        vector<int> ans;
        for (auto& x : mp) {
            if (x.second == mx) ans.push_back(x.first);
        }
        return ans;
    }
};