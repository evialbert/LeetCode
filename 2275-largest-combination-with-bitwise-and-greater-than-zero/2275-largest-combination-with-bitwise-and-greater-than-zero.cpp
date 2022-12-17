class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bits_count(24,0);
        for(auto candidate:candidates)
        {
            for(int i=0;i<24;i++)
            {
                if(candidate&(1<<i))
                {
                    bits_count[i]++;
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<24;i++)
        {
            ans=max(ans,bits_count[i]);
        }
        return ans;
    }
};