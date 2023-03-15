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
     int TotalNode(TreeNode *root){
        if(root==NULL) return 0;
        return 1 + TotalNode(root->left) + TotalNode(root->right);
    }
    bool isCompleteTree(TreeNode* root) {
         int totalnode = TotalNode(root);
        int cnt = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()==false){
           
            TreeNode* curr = q.front();
            if(curr==NULL){
                break;
            }
            q.pop();
            cnt++;
            q.push(curr->left);
            q.push(curr->right);
        }
        
        if(cnt<totalnode) return false;
        return true;
    }
};