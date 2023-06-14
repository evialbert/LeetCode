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
    void inorder(TreeNode* node, vector <int> &inVec){
        if(node == NULL){
            return;
        }
        inorder(node->left, inVec);
        inVec.push_back(node->val);
        inorder(node->right, inVec);
    }

    int getMinimumDifference(TreeNode* root) {
        vector <int> inVec;
        inorder(root, inVec);

        int n = inVec.size();

        int mini = 1e9;

        for(int i=0;i<n-1;i++){
            mini = min(mini, abs(inVec[i]-inVec[i+1]));
        }

        return mini;
    }
};