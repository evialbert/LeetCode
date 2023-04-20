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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode*,int>> q;  //one for add. and second one for index [0,1,.....n-1]
        int ans=0;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            int left=q.front().second;  // left most node index
            int right=q.back().second;   //right most node index
            ans=max(ans,right-left+1);
            while(n--){
                pair t=q.front();
                q.pop();
                if(t.first->left)
                    q.push({t.first->left ,(long long)2*t.second+1});
                if(t.first->right)
                    q.push({t.first->right ,(long long)2*t.second+2});
                
            }
        }
        return ans;
    }
};