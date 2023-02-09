class Solution {
public:
    int dp[50005][3];
    int f(vector<int>& arr,int taken,int idx){
        if(taken >= 2)  return 0;
        if(idx >= arr.size())   return -1e7;
        else if(dp[idx][taken] != -1)   return dp[idx][taken];

        int pick = arr[idx] + f(arr,taken+1,idx+1);
        int notPick = f(arr,taken,idx+1);
        
        if(taken == 1){
            pick = pick - idx;
        }else{
            pick += idx;
        }
                
        return dp[idx][taken] = max(pick,notPick);
    }
    
    int maxScoreSightseeingPair(vector<int>& values) {
        memset(dp,-1,sizeof(dp));
        return f(values,0,0);
    }
};