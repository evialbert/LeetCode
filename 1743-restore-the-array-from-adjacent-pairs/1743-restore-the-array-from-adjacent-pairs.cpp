//Time complexity:O(n)
//Space complexity:O(n)

class Solution {
  private:
  void dfs(int node, unordered_map<int,bool>&visited , unordered_map<int,vector<int>>&adj,vector<int>&ans){
        visited[node] = true;
        ans.push_back(node);
        for(auto it :adj[node]){
            if(!visited[it]) dfs(it,visited,adj,ans);
        }
        return;
}
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>mp;
        for(auto it:adjacentPairs){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        unordered_map<int,bool>visited;
        for(auto ele : mp)visited[ele.first] = false;
        vector<int>ans;

           int start = 0;
        for(auto ele : mp){
           if(ele.second.size() == 1) {
            start = ele.first;
            break;
           }
        }

        dfs(start,visited,mp,ans);
        return ans;
    }
};