class Solution {
public:
    long long dp[23][401][10];
    long long digitDP(vector<int>& num, int n, long long sum, int tight, int min_sum, int max_sum) {
        if (n == -1) {
            return (sum >= min_sum && sum <= max_sum) ? 1 : 0;
        }
        if(dp[n][sum][tight]!=-1)
            return dp[n][sum][tight];
        long long x = 0ll;
        int k = tight ? num[n] : 9;

        for (int i = 0; i <= k; i++) {
             int newTight=num[n]==i?tight:0;
            x += digitDP(num, n - 1, sum + i, newTight, min_sum, max_sum);
            x %= 1000000007;  // Modulo 10^9 + 7
        }

        return dp[n][sum][tight]=x;
    }

    int calc(string n, int min_sum, int max_sum) {
        vector<int> digits;
       for(auto &i:n)
            digits.push_back(i-'0');         
        
     reverse(digits.begin(), digits.end());
        return digitDP(digits, digits.size() - 1, 0, 1, min_sum, max_sum);
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
       // unsigned long long a = stoull(num1), b = stoull(num2);
        memset(dp,-1,sizeof(dp));
      
        long long x=calc(num1, min_sum, max_sum) ;
        memset(dp,-1,sizeof(dp));
         int s=0;
        int c=0;
        for(auto i:num1)
            s+=(i-'0');        
        if(s>=min_sum and s<=max_sum)
            c=1;
        
        long long y=calc(num2 , min_sum, max_sum);
       
       int ans= (y-x+c+1000000007) % 1000000007;
       return ans;
    }
};