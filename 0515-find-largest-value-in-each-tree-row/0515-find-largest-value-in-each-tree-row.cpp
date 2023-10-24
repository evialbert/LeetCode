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
    vector<int> largestValues(TreeNode* root) {
        int level = 0, maxLevel = -1;
        vector<int> result, map(1000, INT_MIN);
        dfs(root, level, maxLevel, map);
        for (int i = 0; i <= maxLevel; i++) {
            result.push_back(map[i]);
        }
        return result;
    }
    
    void dfs(TreeNode *cur, int level, int &maxLevel, vector<int> &map) {
        if (cur == NULL) {
            return;
        }
        maxLevel = max(maxLevel, level);
        map[level] = max(map[level], cur->val);
        dfs(cur->right, level + 1, maxLevel, map);
        dfs(cur->left, level + 1, maxLevel, map);
    }
};