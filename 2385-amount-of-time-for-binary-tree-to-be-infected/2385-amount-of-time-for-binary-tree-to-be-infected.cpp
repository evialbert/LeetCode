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
    vector<vector<int>> gh;
    void traverse(TreeNode* root){
        if(root==nullptr)
            return;
        if(root->left!=nullptr)
        gh[root->val].push_back(root->left->val);
        if(root->right!=nullptr)
        gh[root->val].push_back(root->right->val);
        if(root->left!=nullptr)
        gh[root->left->val].push_back(root->val);
        if(root->right!=nullptr)
        gh[root->right->val].push_back(root->val);
        
        traverse(root->left);
        traverse(root->right);
    }
    int amountOfTime(TreeNode* root, int start) {
        gh=vector<vector<int>>(100001);
        traverse(root);
        
        queue<int> q;
        q.push(start);
        
        vector<bool> vis(100001,false);
        
        int minTimes=0;
        
        vis[start]=true;
        
        while(!q.empty()){
            
            for(int i=q.size();i>0;i--){
                
                int x=q.front();
                q.pop();
                
                for(auto it:gh[x]){
                    if(vis[it]==false){
                        vis[it]=true;
                        q.push(it);
                    }
                }
            }
            
            minTimes++;
        }
        
        return minTimes-1;
    }
};