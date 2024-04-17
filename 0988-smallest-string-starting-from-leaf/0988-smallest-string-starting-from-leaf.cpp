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
    bool check(string & a,string & b){
        cout<<min(a.length(),b.length())<<endl;
        for(int i=0;i<min(a.length(),b.length());i++){
            // cout<<a[i]<<" "<<b[i]<<" "<<endl;
            if(a[i]<b[i]){return true;}
            if(a[i]>b[i]){return false;}
            
        }
        if(a.length()<b.length()){return true;}
        if(b.length()<a.length()){return false;}
        return true;
    }
    void solve(TreeNode* root,string& temp,string& ans){
        if(root->left==NULL && root->right==NULL){
            char c='a'+root->val;
            temp.push_back(c);
            string anoth=temp;
            reverse(anoth.begin(),anoth.end());
            if(check(anoth,ans)){ans=anoth;}
            temp.pop_back();
            return;
        }
        char c='a'+root->val;
        temp.push_back(c);
        if(root->left){
            solve(root->left,temp,ans);
        }
        if(root->right){
            solve(root->right,temp,ans);
        }
        temp.pop_back();
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans="~";
        string temp="";
        solve(root,temp,ans);
        return ans;
    }
};