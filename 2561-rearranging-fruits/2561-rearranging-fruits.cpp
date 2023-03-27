class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        long long ans = 0;
        unordered_map<int, int> m, m1, m2;
        int mi = INT_MAX;
        for(auto &c: basket1)
        {
            m[c]++;
            m1[c]++;
            mi = min(mi, c);
        }
        for(auto &c: basket2)
        {
            m[c]++;
            m2[c]++;
            mi = min(mi, c);
        }
        for(auto &c: m)
        {
            if(c.second%2 != 0) return -1;
        }
        vector<int> v;
        int temp;
        for(auto &c: m1)
        {
            if(c.second == 0) continue;
            if(m1[c.first] != m2[c.first])
            {
                temp = abs(m1[c.first] - m2[c.first]);
                temp /= 2;
                while(temp--) v.push_back(c.first);
            }
        }
        for(auto &c: m2)
        {
            if(c.second == 0) continue;
            if(m1[c.first] == 0)
            {
                temp = abs(m2[c.first] - m1[c.first]);
                temp /= 2;
                while(temp--) v.push_back(c.first);
            }
        }
        sort(v.begin(), v.end());
        for(int i=0; i<v.size()/2; i++)
        {
            if(v[i] > 2*mi) ans += 2*mi;
            else ans += v[i];
        }
        return ans;
    }
};