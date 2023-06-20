class Solution {
public:
    int solve(vector<int> &cost,vector<int> &time,int initial_time,int idx,vector<vector<int>> &dp){
        
         if(initial_time<=0){
            return 0;
        }

        if(idx==cost.size()){
            return 1e9;
        }
        
        if(dp[idx][initial_time]!=-1){
            return dp[idx][initial_time];
        }
       
        
        
       int  taken = cost[idx]+solve(cost,time,initial_time-time[idx]-1,idx+1,dp);
       int nottaken = solve(cost,time,initial_time,idx+1,dp);
        
        return   dp[idx][initial_time] = min(taken,nottaken);
        
    }
    
    
    
    int paintWalls(vector<int>& cost, vector<int>& time){
        int n = time.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(cost,time,n,0,dp);
    }
};