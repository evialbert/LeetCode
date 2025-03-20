class Solution {
public:
    unordered_map<int,int> dp[11][2][82];
    void clean(){
        for(int i=0; i<11; i++){
            for(int sum=0; sum<82; sum++){
                dp[i][0][sum] = {};
                dp[i][1][sum] = {};
            }
        }
    }
    int solve(int i, int n, int tight, int sum, int prod, string& s){
        if(i == n){
            if(!sum) return 0;
            if((prod % sum) == 0) return 1;
            return 0;
        }
        
        if(dp[i][tight][sum].find(prod) != dp[i][tight][sum].end()) return dp[i][tight][sum][prod];
        int ub = tight ? (s[i] - '0') : 9;
        int tot = 0;
        for(int dig=0; dig<=ub; dig++){
            if(dig == 0){
                if(sum == 0) tot += solve(i+1, n, tight & (dig == ub), sum, prod, s);
                else tot += solve(i+1, n, tight & (dig == ub), sum, 0, s);
            }else tot += solve(i+1, n, tight & (dig == ub), sum + dig, prod * dig, s);
        }
        return dp[i][tight][sum][prod] = tot;
    }
    int beautifulNumbers(int l, int r) {
        string sr = to_string(r);
        clean();
        int vr = solve(0, sr.size(), 1, 0, 1, sr);
        string sl = to_string(l-1);
        clean();
        int vl = solve(0, sl.size(), 1, 0, 1, sl);
        return vr - vl;
    }
};