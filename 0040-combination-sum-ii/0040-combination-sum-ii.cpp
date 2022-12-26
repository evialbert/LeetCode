class Solution {

    void solve(int ind,int target,vector<int>& ar,vector<int>& temp,vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<ar.size();i++){
            if(i>ind && ar[i]==ar[i-1]) continue;
            if(ar[i]>target) break;
            temp.push_back(ar[i]);
            solve(i+1,target-ar[i],ar,temp,ans);
            temp.pop_back();
        }
    }
    public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        solve(0,target,candidates,temp,ans);
        return ans;
    }
};