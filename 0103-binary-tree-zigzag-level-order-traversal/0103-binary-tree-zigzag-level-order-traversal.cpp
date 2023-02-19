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
    void zigzagLevelOrderHelper(TreeNode* root, int level, vector<vector<int>>& final){
        if(final.size() <= level) {
            final.push_back(vector<int>());
        }        
        final[level].push_back(root->val);
        if(root->left) zigzagLevelOrderHelper(root->left,level+1,final);
        if(root->right) zigzagLevelOrderHelper(root->right,level+1,final);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> final;
        if(!root) return final;
        zigzagLevelOrderHelper(root,0,final);
        for(int i = 1; i < final.size(); i+=2){
            reverse(final[i].begin(),final[i].end());    
        }
        return final;
    }
};