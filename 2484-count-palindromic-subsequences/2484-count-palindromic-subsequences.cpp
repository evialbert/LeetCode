class Solution {
public:
    int mod = 1e9+7;
    int countPalindromes(string s) {
        if(s.size()<5) return 0;
        int n = s.size();
        vector<vector<vector<int>>> dp1(n,vector<vector<int>>(10,vector<int>(10,0)));
        vector<vector<vector<int>>> dp2(n,vector<vector<int>>(10,vector<int>(10,0)));
        
        vector<int> mp(10,0); mp[s[0]-'0']++;
        for(int i = 1; i<s.size();++i){
            dp1[i] = dp1[i-1];
            for(int j = 0; j<10;++j) dp1[i][s[i]-'0'][j]+=mp[j];
            mp[s[i]-'0']++;
        }
        
        fill(mp.begin(),mp.end(),0);
        mp[s[s.size()-1]-'0']++;
        for(int i = s.size()-2;i>=0;i--){
            dp2[i] = dp2[i+1];
            for(int j = 0; j<10;++j) dp2[i][s[i]-'0'][j]+=mp[j];
            mp[s[i]-'0']++;
        }
        
        long long re = 0;
        for(int i = 2; i<s.size()-2;++i){
            for(int a = 0; a<10;++a){
                for(int b = 0; b<10;++b){
                    re = (re + (long long)dp1[i-1][a][b]*dp2[i+1][a][b])%mod;
                }
            }
        }
        return re;
    }
};