class Solution {
public:
    
    int maximumCandies(vector<int>& candies, long long k) {
        long long l=1,h=0;
        for(int& t:candies)
            h+=t;
        int ans=0;
        while(l<=h)
        {
            long long mid=l+(h-l)/2;
            long long val=0;
            for(auto t:candies)
                val+=(t/mid);
            if(val>=k)
            {
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};