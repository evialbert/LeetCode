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
    
    //Include Exclude Algorithm
    
    vector<int> solve(TreeNode * root){ 
        
        vector<int> v = {0,0}; // {include, exclude}
        
        if(!root)
            return v;
        
        vector<int> l = solve(root->left);
        vector<int> r = solve(root->right);
        
        //if we include node
        v[0] = root->val + l[1] + r[1];
        
        //if we exclude node
        v[1] = max(v[1], l[0]+r[0]); /*include both lower*/
        v[1] = max(v[1], l[1]+r[1]); /*exclude both lower*/
        v[1] = max(v[1], l[0]+r[1]); /*include left*/
        v[1] = max(v[1], l[1]+r[0]); /*include right*/
        
        return v;
    }
    
public:
    int rob(TreeNode* root) {
        
        vector<int> v = solve(root);
        return max(v[0],v[1]);
        
    }
};