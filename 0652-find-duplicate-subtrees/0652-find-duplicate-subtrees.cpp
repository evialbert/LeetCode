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
    unordered_map<string,int>m;
    vector<TreeNode *>v;
    string helper(TreeNode *root){
        if(root==NULL) return "null";
        string left=helper(root->left);
        string right=helper(root->right);
        string res="("+to_string(root->val)+left+right+")";
        // We are adding the parenthesis just to differ the outputs in cases like :
        // 11 as root and 1 as its child 
        // 1 as root and 11 as its child
        // if we do not add the parenthsesis or any marking , the string results like 111
        // by adding the parentheses it results like (1)(11) and (11)(1).
        m[res]++;
        if(m[res]==2) v.push_back(root);
        return res;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        helper(root);
        return v;
    }
};