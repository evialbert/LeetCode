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
class Solution 
{
public:
    void f(TreeNode* root, int &sum, int val)
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) 
        {
            sum += (val*10 + root->val);
            return;
        }

        val = val*10 + root->val;
        f(root->left, sum, val);
        f(root->right, sum, val);
        


    }
    int sumNumbers(TreeNode* root) 
    {
        int sum=0;
        f(root, sum, 0);
        return sum;
    }
};