class Solution {
public:
    int countPalindromes(string s) {
        if(s.length() < 5) return 0;
        int M = 1e9+7;
        vector<vector<int>> cntc(s.length(),vector<int>(10,0)); // we will store cnt of alphabets
        cntc[0][s[0]-'0']++;
        for(int i=1;i<s.length();i++){
            cntc[i] = cntc[i-1];
            cntc[i][s[i]-'0']++;
        }
        // we have the count of chars inclutding i'th char
        vector<vector<vector<int>>> dp(s.length(),vector<vector<int>>(10,vector<int>(10,0)));
        vector<vector<vector<int>>> dpr(s.length(),vector<vector<int>>(10,vector<int>(10,0)));
        for(int i=1;i<s.length();i++){
            // for every i we have to count previous chars that is we are finding ways to make
            // [0-9] s[i] this pair
            dp[i] = dp[i-1];
            for(int j=0;j<10;j++){
                dp[i][j][s[i]-'0'] += cntc[i-1][j];
                dp[i][j][s[i]-'0'] %= M;
            }
        }
        for(int i=s.length()-2;i>=0;i--){
            // for every i we have to count previous chars that is we are finding ways to make
            // [0-9] s[i] this pair
            dpr[i] = dpr[i+1];
            for(int j=0;j<10;j++){
                dpr[i][s[i]-'0'][j] += (cntc[s.length()-1][j] - cntc[i][j]);
                dpr[i][s[i]-'0'][j] %= M;
            }
        }
        long int ans = 0;
        for(int i=2;i<s.length()-2;i++){
            // if we take i'th 
            // we will take count of left side digits
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    ans += ((1ll)*dp[i-1][j][k]*dpr[i+1][k][j]);
                    ans %= M;
                }
            }
        }
        return ans;
    }
};