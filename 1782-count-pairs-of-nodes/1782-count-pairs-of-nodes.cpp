class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> degree(n + 1);
        vector<int>sortdeg;
        vector<int>res;
        map<pair<int, int>, int> mp;
        for(auto it : edges) 
        {
            int x = it[0];
            int y = it[1];
            degree[x] ++;
            degree[y] ++;
            if(x > y) swap(x, y);
            mp[{x, y}] ++;
        }
        for(int i=1;i<=n;i++) 
        {
            sortdeg.push_back(degree[i]);
        }
        sort(sortdeg.begin(), sortdeg.end());
        for(auto it  : queries) {
            int ans = 0;
            int cnt = it+1;
            for(int i=0;i<n;i ++) 
            {
                int j = lower_bound(sortdeg.begin(),sortdeg.end(),cnt-sortdeg[i])-sortdeg.begin();
                ans += n-max(j, i + 1);
            }
            
            for(auto it:mp) 
            {
                int x = it.first.first;
                int y = it.first.second;
                int value = it.second;
                if(degree[x]+degree[y]>=cnt && degree[x]+degree[y]-value<cnt)
                {
                    ans--;
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};