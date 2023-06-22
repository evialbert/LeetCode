class Solution {
public:
    int dp[11][1 << 10][2][2];
    int helper(int ind,int mask,string s,bool is_smaller,bool is_repeated){
        if(ind == s.size())
            return is_repeated ? 1 : 0;
        if(dp[ind][mask][is_smaller][is_repeated] != -1)
            return dp[ind][mask][is_smaller][is_repeated];
        int ans = 0,end = is_smaller ? 9 : s[ind] - '0';
        for(int i=0;i<=end;i++){
           int bitMask = mask;
           bool repeat = is_repeated;
            if(!is_repeated){
                repeat = (mask & (1 << i)) ? true : false;
                if(!repeat)
                    bitMask = mask | (1 << i);
                if(i == 0 && mask == 0)
                    bitMask = 0;
            }
            bool chk = is_smaller ? true : (i != end);
            ans += helper(ind+1,bitMask,s,chk,repeat);
        }
        return dp[ind][mask][is_smaller][is_repeated] = ans;
    }
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        memset(dp,-1,sizeof(dp));
        return helper(0,0,s,false,false);
    }
};