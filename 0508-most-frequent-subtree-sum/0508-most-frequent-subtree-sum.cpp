class Solution {
public:
    int solve(TreeNode* root,unordered_map<int,int> &mp,int& x){
        if(root ==NULL)return 0;
        int l = solve(root->left,mp,x);
        int r = solve(root->right,mp,x);
        x = max(x,++mp[root->val+l+r]);
        return root->val+l+r;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int x = -1;
        unordered_map<int,int> mp;
        solve(root,mp,x);
        vector<int> ans;
        for(auto &i: mp){
            if(i.second == x){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};