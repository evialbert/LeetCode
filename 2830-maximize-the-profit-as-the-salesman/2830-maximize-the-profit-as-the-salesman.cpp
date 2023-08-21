class Solution {
public:

    int solve(int ind, vector<vector<int>> &houseList, vector<vector<int>> &offers, vector<int> &dp)
    {
        if(ind >= houseList.size())
            return 0;

        if(dp[ind] != -1)
            return dp[ind];
        
        int skip = solve(ind+1, houseList, offers, dp), take = 0;

        for(int j=0; j<houseList[ind].size(); j++)
        {
            int i = houseList[ind][j];  /*offer index*/
            int nxt = offers[i][1] + 1; /*nxt available house = num+1 */
            int cur = offers[i][2] + solve(nxt, houseList, offers, dp);
            take = max(take, cur);
        }
        return dp[ind] = max(take, skip);
   }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int m = offers.size();
        //sort(offers.begin(), offers.end(), comp);

        vector<vector<int>> houseList(n);
        for(int i=0; i<m; i++)
        {
            int begin = offers[i][0];
            houseList[begin].push_back(i);
        }
        
        vector<int> dp(n, -1);
        return solve(0, houseList, offers, dp);
    }
};