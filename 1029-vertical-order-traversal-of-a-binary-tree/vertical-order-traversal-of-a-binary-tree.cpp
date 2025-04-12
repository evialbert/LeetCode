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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes; 
        queue<pair<TreeNode*, pair<int, int>>> todo; 
        todo.push({root, {0, 0}});
        
        while (!todo.empty()) {
            pair<TreeNode*, pair<int, int>> front = todo.front();
            todo.pop();
            TreeNode* node = front.first;
            int x = front.second.first, y = front.second.second;
            
            nodes[y][x].insert(node->val);
            
            if (node->left) {
                todo.push({node->left, {x + 1, y - 1}});
            }
            if (node->right) {
                todo.push({node->right, {x + 1, y + 1}});
            }
        }
        
        vector<vector<int>> ans;
        for (auto p = nodes.begin(); p != nodes.end(); ++p) { 
            vector<int> col;
            for (auto q = p->second.begin(); q != p->second.end(); ++q) {
                col.insert(col.end(), q->second.begin(), q->second.end());
            }
            ans.push_back(col);
        }
        return ans; 
    }
};