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
    void inorder(TreeNode* root, vector<int>&ans){
        if(root){
            inorder(root->left, ans);
            ans.push_back(root->val);
            inorder(root->right, ans);
        }
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int>tmp;
        inorder(root,tmp);
        vector<vector<int>>ans;
        for(auto q: queries){
            int l=lower_bound(tmp.begin(), tmp.end(), q)-tmp.begin();
            if(l>=0 && l<=tmp.size()-1){
                if(tmp[l]==q) ans.push_back({tmp[l], tmp[l]});
                else if(l>0 && tmp[l-1]<q && tmp[l]>q) ans.push_back({tmp[l-1], tmp[l]});
                else ans.push_back({-1, tmp[l]});
            }
            else ans.push_back({tmp[l-1], -1});
        }
        return ans;
    }
};