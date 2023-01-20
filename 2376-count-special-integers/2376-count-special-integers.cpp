class Solution {
public:
     string s;
    int dp[2][1<<11][10][2];
    int find(int n, int tight = 1, int mask = 0, int pos = 0, int reapt = 0)
    {
        if (pos == n)
        {
            return reapt == 1;
        }
        if(dp[tight][mask][pos][reapt]!=-1)
        {
            return dp[tight][mask][pos][reapt];
        }
        int ans = 0;
        if (tight == 1)
        {
            for (int i = 0; i <= s[pos] - '0'; i++)
            {
                int new_tight=0;
                if (i == s[pos] - '0')
                {
                    new_tight = 1;
                }
                if (i == 0 && mask == 0)
                {
                    ans += find(n,new_tight, mask, pos + 1, reapt);
                }
                else if (mask &(1 << i))
                {
                    ans+=find(n,new_tight,mask,pos+1,1);
                }
                else
                {
                    ans+=find(n,new_tight,mask|(1<<i),pos+1,reapt);
                }
            }
        }
        else
        {
            for (int i = 0; i <= 9; i++)
            {
                if (i == 0 && mask == 0)
                {
                    ans += find(n, 0, mask, pos + 1, reapt);
                }
                else if (mask &(1 << i))
                {
                    ans+=find(n,0,mask,pos+1,1);
                }
                else
                {
                    ans+=find(n,0,mask|(1<<i),pos+1,reapt);
                }
            }
        }
        return dp[tight][mask][pos][reapt]=ans;
    }
    int countSpecialNumbers(int n) {
        memset(dp,-1,sizeof(dp));
        s=to_string(n);
        return n-find(s.size()); //totol number-reapting number
    }
};