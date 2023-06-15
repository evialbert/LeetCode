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
    #define Node TreeNode
    int maxLevelSum(TreeNode* root) {
        
        
        int maxLevel = 1;
        
        int maxSum = INT_MIN;
        
        queue<Node*> q;
        q.push(root);
        
        int currLevel = 1;
        while(!q.empty())
        {
            
            int size = q.size();
            
            int levelSum = 0;
            while(size--)
            {
                auto front = q.front();
                q.pop();
                
                levelSum += front->val;
                
                
                if(front->left)
                    q.push(front->left);
                
                if(front->right)
                    q.push(front->right);
            }
            if(levelSum > maxSum)
            {
                maxSum  = levelSum;
                maxLevel = currLevel;
            }
            currLevel++;
        }
        
        
        return maxLevel;
        
        
    }
};