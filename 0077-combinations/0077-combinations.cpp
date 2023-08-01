class Solution {
public:
    void backtrack(vector<vector<int>> &ans,vector<int> &comb,int n,int k, int num)
    {
        if(comb.size() == k)
        {
            ans.push_back(comb);
            return;
        }
        for(int i = num;i<=n;i++)
        {
            comb.push_back(i);
            backtrack(ans,comb,n,k,i+1);
            comb.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        backtrack(ans,comb,n,k,1);
        return ans;
    }
};