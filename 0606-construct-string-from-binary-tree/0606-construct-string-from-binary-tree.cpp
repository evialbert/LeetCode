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
    void preOrder(TreeNode* root,string& str) {
        if(!root)
            return;
        str += to_string(root->val);
        // str.push_back(to_string(root->val));
        if(root->left == root->right)
            return;
        str.push_back('(');
        preOrder(root->left,str);
        str.push_back(')');

        if(root->right) {
            str.push_back('(');
            preOrder(root->right,str);
            str.push_back(')');
        }
    }
    string tree2str(TreeNode* root) {
        string str = "";
        preOrder(root,str);
        return str;
    }
};