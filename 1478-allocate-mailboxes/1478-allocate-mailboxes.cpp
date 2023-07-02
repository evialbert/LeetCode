class Solution {
public:
	// place k mailboxes on the location of the house (try every possibilty)
    int dp[105][105][105];
    int solve(int n, int k, int pre[][105], int prev, int i)
    {
        if(i > n) return (k == 0) ? 0 : INT_MAX;
        if(k == 0)
        {
			// when k is 0, just add up all the houses distance to the right
            int sum = 0; 
            for(int j = prev + 1; j <= n; j++)
            {
                sum += pre[prev][j];
            }
            return sum;
        }
        
        if(dp[prev][i][k] != -1) return dp[prev][i][k];
		
        // option 1: don't consider this house
        int a = solve(n, k, pre, prev, i + 1); 
		
		// option 2: consider this house (i.e, place mailbox at this location) and
		// add the minimum distance between the current and the 
		// previously placed mailbox of all the houses in between
        
		int b = INT_MAX; 
        int sum = 0;
		
        for(int j = prev + 1; j < i; j++)
        {
            if(prev != 0) sum += min(pre[prev][j], pre[i][j]);
            else sum += pre[i][j];
        }
        
        int val = solve(n, k - 1, pre, i, i + 1);
        if(val != INT_MAX) b = sum + val;
        
        return dp[prev][i][k] = min(a, b);
    }
    
    int minDistance(vector<int>& house, int k) {
        int n = house.size();
        int pre[105][105]; // pre[i][j] stores the distance from ith house to jth house
        sort(house.begin(), house.end());
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                pre[i + 1][j + 1] = abs(house[i] - house[j]);
            }
        }
        
        memset(dp, -1, sizeof dp);
        return solve(n, k, pre, 0, 1);
    }
};