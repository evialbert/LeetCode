class Solution {
public:
    void recur(int i, int t, vector<int> &v, vector<int> &temp, set<vector<int>> &ans){
      if(t == 0){
        ans.insert(temp);
        return;
      }
      for(int idx = i; idx < v.size(); idx++){
        if(idx > i and v[idx] == v[idx - 1]) continue;
        if(t - v[idx] < 0) break;
        temp.emplace_back(v[idx]);
        recur(idx + 1, t - v[idx], v, temp, ans);
        temp.pop_back();
      }
    }
    vector<vector<int>> combinationSum2(vector<int>& v, int t) {
      set<vector<int>> anst;
      vector<int> temp;
      sort(v.begin(), v.end());
      recur(0, t, v, temp, anst);
      vector<vector<int>> ans(anst.begin(), anst.end());
      return ans;
    }
};