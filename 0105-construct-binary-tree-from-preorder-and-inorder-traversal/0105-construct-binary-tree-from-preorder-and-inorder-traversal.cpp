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
    int index=0;
    unordered_map<int,int> mp;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int lowerBound,int upperBound){
        if(lowerBound > upperBound) return NULL;
        TreeNode* res=new TreeNode(preorder[index++]);
        if(lowerBound == upperBound) return res;
        int mid=mp[res->val];
        res->left=solve(preorder,inorder,lowerBound,mid-1);
        res->right=solve(preorder,inorder,mid+1,upperBound);
        return res;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mp.clear();
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return solve(preorder,inorder,0,inorder.size()-1);
    }
};