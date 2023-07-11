/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void getNodes(TreeNode* root, int k){
        if(root==nullptr) return;
        if(root==Target) return;
        
        if(k==0)result.push_back(root->val);
        else
        getNodes(root->left,k-1), getNodes(root->right,k-1);
    }
    
    bool nodePath(TreeNode* root, TreeNode* target){
        if(root==nullptr) return false;
        if(root==target) return true;
        nodes.push(root);
        if(nodePath(root->left,target) or nodePath(root->right,target)) 
            return true;
        nodes.pop();
        return false;
    }

public:
    vector<int> result;
    stack<TreeNode*> nodes;
    TreeNode* Target;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0) return {target->val};
        getNodes(target,k);
        Target = target;
        nodePath(root,target);
        while(!nodes.empty()){
            if(k==0) break; 
            getNodes(nodes.top(),--k);
            Target = nodes.top();
            nodes.pop();
        }       
        return result;
    }
};