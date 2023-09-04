class Solution {
public:
    int mod = 1e9+7;
    long long solve(int idx,string& s,unordered_map<char,int>& m,int k,int sum,int &maxs,map<vector<long long>,int>&dp)
    {
        if(k==0 && sum==maxs)
            return 1;
        if(idx>=s.size() || k<0)
            return 0;
        if(dp.find({idx,k,sum})!=dp.end())
            return dp[{idx,k,sum}];
        long long tak1 = ((m[s[idx]]%mod)*(solve(idx+1,s,m,k-1,sum+m[s[idx]],maxs,dp))%mod)%mod;
        long long tak2 = solve(idx+1,s,m,k,sum,maxs,dp)%mod;
        return dp[{idx,k,sum}] = (tak1+tak2)%mod;
    }
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        if(k>26)
            return 0;
        int maxs = 0;
        unordered_map<char,int> m;
        for(auto &i:s)
            m[i]++;
        priority_queue<int> pq;
        for(auto &i:m)
            pq.push(i.second);
        int cnt = k;
        while(cnt)
        {
            maxs+=pq.top();
            pq.pop();
            cnt--;
        }
        map<vector<long long>,int> dp;
        string tms = "";
        for(auto &i:m)
            tms+=i.first;
        sort(tms.begin(),tms.end());
        return solve(0,tms,m,k,0,maxs,dp);
    }
};