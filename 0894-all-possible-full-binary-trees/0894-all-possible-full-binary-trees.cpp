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
    vector<vector<TreeNode*>>dp;
    vector<TreeNode*> helper(int n){
       if(n==1){
           TreeNode* newnode = new TreeNode(0);
           return {newnode};
       }
       if(dp[n].size()!=0)return dp[n];
       vector<TreeNode*> root;

       for(int i=1;i<=n/2;i+=2){
           vector<TreeNode*> left= helper(i);
           vector<TreeNode*> right= helper(n-i-1);

           for(auto &l: left){
               for(auto &r: right){
                   TreeNode* newnode=new TreeNode(0);
                   newnode->left=l;
                   newnode->right=r;
                   root.push_back(newnode);

               }
           }

           if(i!=n/2){
            for(auto &l: right){
               for(auto &r: left){
                   TreeNode* newnode=new TreeNode(0);
                   newnode->left=l;
                   newnode->right=r;
                   root.push_back(newnode);

                }
            }
           }
        }

        return dp[n]=root;

    }
    vector<TreeNode*> allPossibleFBT(int n) {
        dp.resize(n+1);
        if(n%2==0) return {};
        return helper(n);
    }
}; 