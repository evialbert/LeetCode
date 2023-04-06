class Solution {
vector<vector<int>>result;
public:
    void dfs(int n, int target, vector<int> &candidates, vector<int>a)
    {
        if(n==0)
            return;
        if(target==0)
        {result.push_back(a);
         return;}
   
        if(candidates[n-1]<=target)
        {
            a.push_back(candidates[n-1]);
            dfs(n,target-candidates[n-1],candidates,a);
            a.pop_back();
        }
        dfs(n-1,target,candidates,a);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>a;
        dfs(n,target,candidates,a);
        return result;
    }
};