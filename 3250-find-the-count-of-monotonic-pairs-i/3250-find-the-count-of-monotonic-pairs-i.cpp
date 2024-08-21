class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size(); 
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(51, vector<int>(51, 0))); 

        int num = nums[0];
        for (int k = 0; k <= num; k++) { 
            int l = abs(num - k);
            dp[0][k][l] = 1;
        }

        for (int i = 1; i < n; i++) { 
            int num = nums[i-1]; 
            for (int j = 0; j <= num; j++) {
                int k = num - j;
                int curr=nums[i];
                for (int l = 0; l <= curr; l++) { 
                    int x=abs(curr-l);
                    if(l>=j && x<=k){
                        dp[i][l][x] = (dp[i][l][x] + dp[i-1][j][k]) % 1000000007 ;
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i <= 50; i++) { 
            for (int j = 0; j <= 50; j++) { 
                ans = (ans + dp[n-1][i][j]) % 1000000007;
            }
        }
        return ans;
    }
};