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
  
    int sumNumbers(TreeNode* root) {
      int ans=0;
      stack<pair<TreeNode*, int>> st;
      st.push({root, root->val});
      while(!st.empty())
      {
        
          pair<TreeNode*, int> f=st.top();
          st.pop();
          if(!f.first->left && !f.first->right)
          {
              
              ans+=f.second;
          }
          if(f.first->left)
          {
              st.push({f.first->left,f.second*10+f.first->left->val});
            
          } 

           if(f.first->right)
          {
              st.push({f.first->right,f.second*10+f.first->right->val});
            
          } 
      }
      return ans;
        
    }
};