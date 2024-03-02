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
    void inorder(TreeNode* root,vector<int>& in){
        if(root == NULL) return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    void make(vector<int> in,TreeNode* &root,TreeNode* r,int s,int e,string str){
        if(s>e) return;
        int m = s + (e-s)/2;
        TreeNode* node = new TreeNode(in[m]);
        if(str == ""){
            root = node;
        }
        else if(str == "R"){
            r->right = node;
        }
        else if(str == "L"){
            r->left = node;
        }

        if(s == e) return;

        make(in,root,node,s,m-1,"L");
        make(in,root,node,m+1,e,"R");
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorder(root,in);

        TreeNode* nroot = NULL;
        TreeNode* r = NULL;
        string s = "";
        make(in,nroot,r,0,in.size()-1,"");
        return nroot;
    }
};