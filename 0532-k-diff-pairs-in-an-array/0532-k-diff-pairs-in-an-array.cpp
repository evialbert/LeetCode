class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> m1;
        vector<int> v1;
        int ans = 0;
        for(auto x : nums)
        {
            if(m1[x] == 0)
            {
                v1.push_back(x);
            }
            m1[x]++;
        }
        if(k == 0)
        {
            for(auto x : v1)
            {
                if(m1[x] > 1)
                {
                    ans++;
                }
            }
        }
        else
        {
            for(auto x : v1)
            {
                if(m1[x + k] > 0)
                {
                    ans++;
                }
                if(m1[x - k] > 0)
                {
                    ans++;
                }
            }
            ans /= 2;
        }
        return ans;
    }
};