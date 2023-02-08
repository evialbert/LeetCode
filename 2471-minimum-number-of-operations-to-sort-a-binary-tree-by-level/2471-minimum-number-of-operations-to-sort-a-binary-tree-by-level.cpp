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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        int c=0;
        q.push(root);
        while(!q.empty())
        {
            vector<int>a,b;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode*t=q.front();
                q.pop();
                if(t->left!=NULL)
                   q.push(t->left);
                if(t->right!=NULL)
                   q.push(t->right);
                a.emplace_back(t->val);
                b.emplace_back(t->val);
            }
            vector<pair<int,int>>p;
            for(int i=0;i<a.size();i++)
                p.emplace_back(make_pair(a[i],i));
            sort(p.begin(),p.end());
            for(int i=0;i<p.size();i++)
            {
                if(i==p[i].second)
                    continue;
                else
                {
                    c++;
                    swap(p[i],p[p[i].second]);
                    i--;
                }
            }
        }
        return c;
    }
};