class Solution {
public:
    int dp[1000][10][2];
    int mod = 1e9 + 7;
    int f(int i,int p,string& s,int tight,int b){
        //cout<<s<<endl;
        if(i == s.size()) return 1;
        int ans = 0;
        if(dp[i][p][tight] != -1) return dp[i][p][tight];
        for(int j = max(0,p);j<b;j++){
            int x = s[i] - '0';
            if(tight && j>x) break;
            ans = (ans + f(i+1,j,s,tight&(x==j),b))%mod;
        }
        return dp[i][p][tight] = ans;
    }
    string divideByBase(string num, int base, int &r) {
        string ans;
        r = 0;
        for(auto i:num){
            int x = (i - '0') + r*10;
            ans += char(x/base + '0');
            r = x%base;
        }
        int i = 0;
        while(i<ans.size() && ans[i] == '0') i++;
        if(i == ans.size()) return "0";
        return ans.substr(i);
    }

    
    string convertToBaseUpTo10(string numStr, int base) {
        string ans;
        while(numStr != "0"){
            int r = 0;
            numStr = divideByBase(numStr,base,r);
            ans = ans + char(r + '0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    void sub(string& s){
        int i = s.size() - 1;
        while(s[i] - '0' == 0) i--;
        s[i]--;
        for(int j=i+1;j<s.size();j++) s[j] = '9';
        return ;
    }

    int countNumbers(string l, string r, int b) {
        string br = convertToBaseUpTo10(r,b);
        sub(l);
        string bl = convertToBaseUpTo10(l,b);
        
        for(int i=0;i<br.size();i++){
            for(int j=0;j<10;j++) dp[i][j][0] = dp[i][j][1] = -1;
        }
        int ans = f(0,0,br,1,b);
        
        for(int i=0;i<br.size();i++){
            for(int j=0;j<10;j++) dp[i][j][0] = dp[i][j][1] = -1;
        }
        
        ans = (ans - f(0,0,bl,1,b) + mod)%mod;
        return ans;
    }
};