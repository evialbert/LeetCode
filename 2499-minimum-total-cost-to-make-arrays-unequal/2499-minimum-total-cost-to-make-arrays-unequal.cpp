class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> mp(n+1);
        for(int i=0;i<n;i++)
        {
            mp[nums1[i]]++;
            mp[nums2[i]]++;
        }
        
        for(auto &freq : mp)
        {
            if(freq>n)
                return -1;
            freq=0;
        }
    
        long long ans=0ll;
        int counter=0;
        for(int i=0;i<n;i++)
        {
            if(nums1[i]==nums2[i])
            {
                mp[nums1[i]]++;
                counter++;
                ans=ans+i*1ll;
            }
        }

        long long maxFreqVal=-1;
        for(int i=1;i<=n;i++)
        {
            int freq=mp[i];
            if(counter-freq<freq)
                maxFreqVal=i;
        }

        if(maxFreqVal==-1)
            return ans;
        mp[maxFreqVal]=2*mp[maxFreqVal]-counter;
        for(int i=0;i<n;i++)
        {
            if(nums1[i]==nums2[i])//these have already been considered
                continue;
            if(nums1[i]!=maxFreqVal && nums2[i]!=maxFreqVal && mp[maxFreqVal]>0)
            {
                ans=ans+i*1ll;
                mp[maxFreqVal]--;
            }
        }

        return ans;
    }
};