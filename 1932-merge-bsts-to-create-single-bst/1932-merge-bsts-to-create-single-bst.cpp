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
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> root_mp, chld_mp;
        for(auto& n : trees) {
            if(n->left != nullptr) {
                if(chld_mp.find(n->left->val) != chld_mp.end()) return nullptr;
                chld_mp[n->left->val] = n->left;
            }
            if(n->right != nullptr) {
                if(chld_mp.find(n->right->val) != chld_mp.end()) return nullptr;
                chld_mp[n->right->val] = n->right;
            }
            root_mp[n->val] = n;
        }

        TreeNode* res = nullptr;
        for(auto & [k, v] : root_mp) {
            if(chld_mp.find(k) == chld_mp.end()) {
                if(res != nullptr) return nullptr;
                res = v;
            }
        }

        function<void(TreeNode*, TreeNode*, int, int)> dfs = [&](TreeNode* p, TreeNode* t, int l, int h) {
            if(t == nullptr) return;
            if(t->val <= l || t->val >= h) {
                res = nullptr;
                return;
            }
            int v = t->val;
            if(root_mp.find(v) == root_mp.end()) return;
            auto r = root_mp[v];
            root_mp.erase(r->val);
            if(p->left == t) p->left = r;
            else p->right = r;
            dfs(r, r->left, l, min(h, r->val));
            dfs(r, r->right, max(l, r->val), h);
        };
        if(res != nullptr) dfs(res, res->left, INT_MIN, res->val);
        if(res != nullptr) dfs(res, res->right, res->val, INT_MAX);
        return root_mp.size() == 1 ? res : nullptr;
    }
};