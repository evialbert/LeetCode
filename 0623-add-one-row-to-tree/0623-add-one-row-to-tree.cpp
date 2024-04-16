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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*>q;
        q.push(root);
        int cnt=1;
        if(depth==1)
        {
                    TreeNode *t1=new TreeNode(val);
                    t1->left=root;
                    return t1;
        }
        while(!q.empty())
        {
            int t=q.size();
            cnt++;
            while(t--)
            {
                TreeNode *curr=q.front();
                q.pop();
                if(cnt==depth)
                {
                    TreeNode *temp1=curr->left,*temp2=curr->right;
                    curr->left=new TreeNode(val);
                    curr->left->left=temp1;
                    curr->right=new TreeNode(val);
                    curr->right->right=temp2;
                }
                if(curr->left)
                  q.push(curr->left);
                if(curr->right)
                  q.push(curr->right);
            }
            if(cnt==depth)
                    break;
        }
        return root;
    }
};