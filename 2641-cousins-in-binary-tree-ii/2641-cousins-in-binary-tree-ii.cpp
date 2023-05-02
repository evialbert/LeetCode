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
    void UpdateTree(TreeNode* root, int level, vector<long long>& levelSum)
    {
        if(root==NULL)    return;
        int sum = 0;
        if(root->left)    sum += root->left->val;
        if(root->right)   sum += root->right->val;
        if(root->left)    root->left->val = levelSum[level+1] - sum;
        if(root->right)   root->right->val = levelSum[level+1] - sum;

        UpdateTree(root->left, level+1, levelSum);
        UpdateTree(root->right, level+1, levelSum);  
    }

    vector<long long> CalculateLevelSum(TreeNode* root)
    {
        vector<long long> levelSum;
        queue<TreeNode *> q; 
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            int sum = 0;
            for(int i=0; i<n; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                if(curr->left)    q.push(curr->left);
                if(curr->right)   q.push(curr->right);
            }

            levelSum.push_back(sum);
        }

        return levelSum;
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<long long> levelSum = CalculateLevelSum(root);
        int level = 0;
        UpdateTree(root, level, levelSum);
        root->val = 0;
        return root;
    }
};