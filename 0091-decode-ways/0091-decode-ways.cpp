class Solution {
public:
	int solve(vector<int>& dp, int i,string& s)
	{
		if(i<0)
			return 1;
		if(dp[i]!=-1)
			return dp[i];
		dp[i]=0;
		if(i==0)
		{
			if(s[i]=='0')
				return dp[i]=0;
			return dp[i]=1;
		}
		if(s[i]!='0')
			dp[i]=solve(dp,i-1,s);
		if((s[i-1]-'0')*10 + s[i]-'0'<=26 && (s[i-1]-'0')*10 + s[i]-'0'>=10)
			dp[i]+=solve(dp,i-2,s);    
		return dp[i];
	}
	int numDecodings(string s) {
		int n = s.length();
		if(s[0]=='0')
			return 0;
		vector<int> dp(n,-1);
		solve(dp,n-1,s);
		return dp.back();
	}
};