class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        long long ans=0;

        int inc=0,dec=0;
        vector<int> numsE;
        vector<int> numsO;
        vector<int> targetE;
        vector<int> targetO;
        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            numsE.push_back(nums[i]);
            else
            numsO.push_back(nums[i]);

            if(target[i]%2==0)
            targetE.push_back(target[i]);
            else
            targetO.push_back(target[i]);
        }

        for(int i=0;i<numsE.size();i++)
        {
            if(numsE[i]>targetE[i])
            {
                ans=ans+(numsE[i]-targetE[i])/2;
            }
        }

        for(int i=0;i<numsO.size();i++)
        {
            if(numsO[i]>targetO[i])
            ans=ans+(numsO[i]-targetO[i])/2;
        }
        return ans;
    }
};