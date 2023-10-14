class Solution {
public: 
    
    int n , dp[501][501]; 
    
    int solve(int i , int left , vector<int>&cost , vector<int>& time){

        if(left<=0)return 0; 
        if(i>=n)return 1e9; 
        
        if(dp[i][left]!=-1)
        return dp[i][left]; 

        int paint = cost[i] + solve(i+1 , left-1-time[i] , cost , time); 
        int notPaint = solve(i+1 , left , cost , time); 

        return dp[i][left] = min(paint , notPaint); 
    }

    int paintWalls(vector<int>& cost, vector<int>& time) { 

        n = cost.size();  
        memset(dp , -1 , sizeof(dp));  
        return solve(0 , n , cost , time); 

    }
};