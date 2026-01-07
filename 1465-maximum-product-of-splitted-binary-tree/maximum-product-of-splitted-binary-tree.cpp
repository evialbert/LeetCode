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
long long total,ans;
const int mod=1e9+7;
    long long dfs(TreeNode* root){
        if(!root)return 0;
        return root->val+dfs(root->left)+dfs(root->right);
    }
    long long  dfs1(TreeNode* root){
        if(!root)return 0;
        int left_sum=dfs1(root->left);
        int right_sum=dfs1(root->right);
        int subarraysum=root->val+left_sum+right_sum;
        ans=max(ans,subarraysum*(total-subarraysum));
        return subarraysum;
    }
    int maxProduct(TreeNode* root) {
        total=dfs(root);
        ans=0;
       dfs1(root);
        ans=ans%mod;
       return (int)ans;
    }
};