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
    int solve(TreeNode * root,int sum)
    {
        if(root == NULL)
        {
            return 0;
        }

        sum = sum * 10 +root->val;     //calculate the sum

        if(root->left == NULL && root->right == NULL)
        {
            return sum;
        }

        return solve(root->left,sum)+solve(root->right,sum);  //iterate over the elements

    }
    int sumNumbers(TreeNode* root) { 
        int sum = 0 ;
        return solve(root,sum);   //using DFS
    }
};