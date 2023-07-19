class Solution {
public:
    int n;
    int helper(int v,int time ,vector<unordered_map<int,int>> &graph ,vector<vector<int>>&dp , vector<int>& fees ){
        if(v == n-1)
               return fees[n-1];
        if(dp[v][time]!=-1)
            return dp[v][time];
        int ans = INT_MAX;
        for(auto &g: graph[v]){
            if(time-g.second>=0){
                int cost = helper(g.first,time-g.second, graph,dp,fees);
                ans = min(ans,cost);
            }
        }
        return dp[v][time] = ans!=INT_MAX ? ans + fees[v] : INT_MAX;
    }
    
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        n = passingFees.size(); //no of vertices
        vector<vector<int>> dp(n, vector<int>(maxTime+1 , -1));
        //you have to go from 0 to n-1 within maxTime by spending the minimum amount of money. 
        
        vector<unordered_map<int,int>> graph(n);
        //Important point is to note that there may be multiple roads of differing travel times connecting the same two cities. So take the route with the minimum cost. 
        for(auto & e: edges){
            if( graph[e[0]][e[1]]==0)
                graph[e[0]][e[1]] = e[2];
            else 
                 graph[e[0]][e[1]] = min( graph[e[0]][e[1]] , e[2]);
            
            if(graph[e[1]][e[0]] == 0)                
                graph[e[1]][e[0]] = e[2];
            else 
                graph[e[1]][e[0]] = min(graph[e[1]][e[0]] , e[2]);
        }
        int ans =  helper(0,maxTime,graph,dp,passingFees);                    
        return ans==INT_MAX ? -1 : ans;
    }
};