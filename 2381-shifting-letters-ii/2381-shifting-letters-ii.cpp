class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>&q) {
        int n=s.size();
        vector<int>dp(n+1,0);
        for(auto it:q)
        {
            if(it[2]==0)
            {
                dp[it[0]]-=1;
                dp[it[1]+1]+=1;
            }
            else
            {
                dp[it[0]]+=1;
                dp[it[1]+1]-=1;
            }
            dp[it[0]]=(dp[it[0]]+26)%26;
            dp[it[1]]=(dp[it[1]]+26)%26;
        }
        for(int i=0;i<n;i++)
        {
            if(i)
            {
                dp[i]+=dp[i-1];
            }
        }
        for(int i=0;i<n;i++)
        {
            int sum=(dp[i]+(s[i]-'a')+26)%26;
            s[i]=(sum+'a');
        }
        return s;
    }
};