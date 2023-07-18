class Solution {
public:
	int stoneGameVIII(vector<int>& stones) {
		int n =stones.size();
		vector<int> prefix(n,0);
		prefix[0]=stones[0];
		for(int i=1;i<n;i++)
		{
			prefix[i]=prefix[i-1]+stones[i];
		}
		vector<int> dp(n);
		dp[n-1]=prefix[n-1]; // Because the other player will not be able to play the game as only 1 stone will remain
		for(int i=n-2;i>=1;i--)
		{
			dp[i]=max(prefix[i]-dp[i+1], dp[i+1]);

		}
		return dp[1];
	}
};