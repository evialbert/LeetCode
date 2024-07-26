class Solution {
public:
    int dp[23][23][23][23];
    int helper(vector<int>& horizontalCut, vector<int>& verticalCut, int starti, int endi, int startj, int endj){
        if(endi-starti==1 and endj-startj==1)
            return 0;
        
        int res=INT_MAX;
        
        if(dp[starti][endi][startj][endj]!=-1)
            return dp[starti][endi][startj][endj];
        
        for(int i=starti+1;i<endi;i++){
            // cout<<" i: "<<i<<"\n";
            int a=horizontalCut[i-1]+helper(horizontalCut, verticalCut, starti, i, startj, endj)+helper(horizontalCut, verticalCut, i, endi, startj, endj);
            
            res=min(res, a);
        }
        
        
        for(int j=startj+1;j<endj;j++){
            // cout<<" j: "<<j<<"\n"; 
            int b=verticalCut[j-1]+helper(horizontalCut, verticalCut, starti, endi, startj, j)+helper(horizontalCut, verticalCut, starti, endi, j, endj);
            res=min(res, b);
        }
        
        return dp[starti][endi][startj][endj]=res;
    }
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        memset(dp, -1, sizeof(dp));
        return helper(horizontalCut, verticalCut, 0, m, 0, n);
    }
};