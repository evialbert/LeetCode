class Solution {
public:
    void dfs(int node, int parent, vector<vector<int>>& adj, unordered_map<long long,long long>& mp, vector<long long>& nval, long long& ans)
    {
        //for root node, no ancestors
        if(node != 0) ans += mp[nval[node]];
        mp[nval[node]]++;
        for(int child: adj[node])
        {
            if (child != parent)
                dfs(child, node, adj, mp, nval, ans);
        }
        //removing the child count for backtrack
        mp[nval[node]]--;
    }

    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        //For perfect square, each prime factor must have an even power. 
        //sqrt(2^4 5^2) = 2^2 5^1
        //if we multiply two numbers, the powers of factors gets added
        //we can neglect the even powers and only consider the odd ones for perfect sqaures.
        //We will only consider the square free prime factors(factors with power of one only)
        //two numbers will form a perfect square if their square free factors are equal as they will add to a even power

        //creating adjacency list
        vector<vector<int>> adj(n);
        for(auto& e: edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        //max nums[i] goes to 10^5
        int MX = 100000;
        //creating a dp to store the sqaure free part of all the numbers
        vector<long long>dp(MX+1);
        for(int i=1; i<=MX; i++)
            dp[i] = i;
        for(int i=2; i * i <=MX; i++)
        {
            //removing sqaures from each number
            long long sq = (long long)1 * i * i;
            //increasing by sq as middle numbers will not be divisible by sq
            for(int j=sq; j<=MX; j+=sq)
            {
                while(dp[j] % sq == 0) dp[j] /= sq;
            }
        }
        //storing sqaure free part by node
        vector<long long> nval(n);
        for (int i = 0; i < n; i++) nval[i] = dp[nums[i]];

        //map to store the count of square free factors 
        unordered_map<long long,long long>mp;
        //parent of root node is -1
        long long ans = 0;
        dfs(0,-1,adj,mp,nval,ans);
        return ans;
    }
};