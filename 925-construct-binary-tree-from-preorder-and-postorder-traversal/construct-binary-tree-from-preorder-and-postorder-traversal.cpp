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
    void build(int i,vector<int>&preorder,vector<int>&k,vector<bool>&dp,TreeNode* &root){
        bool p=0;
        bool l=0;
        
        // dp[preorder[i]]=1;
        for(int j=i+1;j<preorder.size();j++){
            int a=preorder[i],b=preorder[j];
            if(dp[b]) continue;
            if(k[a]>k[b]){
                if(!p){
                    p=1;
                    root->left=new TreeNode(b);
                    dp[b]=1;
                    build(j,preorder,k,dp,root->left);
                }
                else{
                    root->right=new TreeNode(b);
                    dp[b]=1;
                    build(j,preorder,k,dp,root->right);
                    break;
                }
            }
        }

    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        vector<int>k(n+1);
        for(int i=0;i<n;i++){
            k[postorder[i]]=i+1;
        }
        vector<bool>dp(n+1,0);
        TreeNode* root=new TreeNode(preorder[0]);
        dp[root->val]=1;
        build(0,preorder,k,dp,root);
        return root;
    }
};