class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> adj[n];
        
        unordered_map<int,int> indegree;
        for(vector<int>&v : edges){
            adj[v[0]].push_back(v[1]);
            indegree[v[1]]++;
        }
        
        queue<int> q;
        vector<vector<int>> dp(n,vector<int> (26,0));
        for(int i=0;i<n;i++){
            if(indegree[i] == 0) {
                q.push(i);
                dp[i][colors[i] - 'a'] = 1;
            }
        }
        
        int visitedNodes = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            visitedNodes++;
            for(int child : adj[node]){
                for(int i=0;i<26;i++){
                    dp[child][i] = max(dp[child][i],dp[node][i] + (i == (colors[child] - 'a')));
                }

                indegree[child]--;
                if(indegree[child] == 0) q.push(child);
            }
        }
        
        if(visitedNodes < n) return -1; //means cycle present
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int clr=0;clr<26;clr++){
                ans = max(ans,dp[i][clr]);
            }
        }
        
        return ans;
    }
};