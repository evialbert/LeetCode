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
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        calculate(root,ans);
        return ans;
    }
    
    vector<int> calculate(TreeNode* root, int & ans ){
        if(!root)  return {0,0};
        vector<int> left = calculate(root->left,ans);
        vector<int> right = calculate(root->right,ans);
        int sum,count;
        sum = left[0]+right[0]+root->val;
        count = left[1]+right[1]+1;
        if(sum/count==root->val) ans++;
        
        return {sum,count};
    }
};