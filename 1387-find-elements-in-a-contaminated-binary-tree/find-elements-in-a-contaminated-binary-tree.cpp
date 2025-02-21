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

class FindElements
{
     std::bitset<1'000'001> d_values{false};

public:
    FindElements(TreeNode* root)
    {
        root->val = 0;

        queue<TreeNode *> q;
        q.push(root);

        while (not q.empty())
        {
            TreeNode const *currNode = q.front();
            q.pop();

            int const val = currNode->val;

            if (val > 1'000'001)
                continue;

            d_values[val] = true;

            if (currNode->left)
            {
                currNode->left->val = 2 * val + 1;
                q.push(currNode->left);
            }

            if (currNode->right)
            {
                currNode->right->val = 2 * val + 2;
                q.push(currNode->right);
            }
        }
    }
    
    inline bool find(int target) const
    {
        return d_values[target];
    }
};