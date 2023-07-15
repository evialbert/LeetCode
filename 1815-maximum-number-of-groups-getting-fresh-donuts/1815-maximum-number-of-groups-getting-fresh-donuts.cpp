class Solution {
public:
    int maxHappyGroups(int bs, vector<int>& groups) {
        vector<int> freq(bs, 0);
        long long sum = 0;
        for(auto it : groups)   freq[it%bs]++, sum += it;
        map<vector<int>, int> dp;
        int ans = freq[0] + (sum%bs != 0);

        // Remove all pairs that makes remainder zero
        for(int i = 1 ; i < bs ; i++){
            if(i != bs-i){
                ans += min(freq[i], freq[bs-i]);
                int temp = min(freq[i], freq[bs-i]);
                freq[i] -= temp;
                freq[bs-i] -= temp;
            }
        }
        return maxGroups(bs, freq, 0, dp) + ans;
    }

    int maxGroups(int bs, vector<int>& freq, int rem, map<vector<int>, int>& dp){
        int ans = 0;
        if(dp.count(freq))    return dp[freq];
        for(int i = 1 ; i < bs ; i++){
            if(freq[i] > 0){
                freq[i]--;
                ans = max(ans, ((rem+i)%bs == 0) + maxGroups(bs, freq, (rem+i)%bs, dp));
                freq[i]++;
            }
        }
        return dp[freq] = ans;
    }
};