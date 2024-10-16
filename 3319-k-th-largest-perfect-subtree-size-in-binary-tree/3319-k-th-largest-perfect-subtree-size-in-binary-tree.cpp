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
    int dfs(TreeNode* root,vector<int> &v){
        if(root==NULL){
            return 0;
        }
        int l=dfs(root->left,v);
        int r=dfs(root->right,v);

        if(l==r){
            v.push_back(l+r+1);
            return l+r+1;
        }
        return -1;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> v;
        int z=dfs(root,v);
        sort(v.rbegin(),v.rend());
        return k>v.size()?-1:v[k-1];
    }
};