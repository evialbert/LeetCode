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
    unordered_map<int, vector<int>> mp;
public:
    void dfs(TreeNode* root){
        if(root == NULL)return;
        if(root->left){
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);
            dfs(root->left);
        }
        if(root->right){
            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
            dfs(root->right);
        }
    }

    int dfs2(int u, unordered_set<int> &vis){
        vis.insert(u);
        int ans = 0;
        for(auto v : mp[u]){
            if(vis.count(v) == 0){
                ans = max(ans, 1 + dfs2(v, vis));
            }
        }
        return ans;
    }

    int amountOfTime(TreeNode* root, int start) {
        dfs(root);
        unordered_set<int> vis;
        return dfs2(start, vis);
    }
};