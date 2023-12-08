class Solution {
public:
    vector<vector<vector<int>>>dp;
    int solve(vector<int>& boxes,int left,int right,int count){
        if(left > right)
            return 0;
        if(dp[left][right][count] != -1)
            return dp[left][right][count];
        int i = left;
        int c = count;
        while(left + 1 <= right && boxes[left] == boxes[left + 1]){
            left++;
            count++;
        }
        int ans = (count+1)*(count+1) + solve(boxes,left+1,right,0);
        for(int k = left+1;k <= right;k++)
            if(boxes[k] == boxes[left])
                ans = max(ans,solve(boxes,left+1,k-1,0) + solve(boxes,k,right,count+1));
        return dp[i][right][c] = ans;
    }
    int removeBoxes(vector<int>& boxes) {
        dp = vector<vector<vector<int>>>(boxes.size(),vector<vector<int>>(boxes.size(),vector<int>(boxes.size(),-1)));
        return solve(boxes,0,boxes.size()-1,0);
    }
};