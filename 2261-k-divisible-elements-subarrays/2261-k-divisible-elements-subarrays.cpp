class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size();
        vector<bool>div(n);
        vector<int>prefix;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%p==0)
                div[i]=1;
            else
                div[i]=0;
            sum+=div[i];
            prefix.push_back(sum);          
        }
        

        int prev=0;
        set<vector<int>>s;
        for(int i=0;i<=n-1;i++)
        {
            int lastInd=upper_bound(prefix.begin(),prefix.end(),k+prev)-prefix.begin()-1;
            prev=prefix[i];
            vector<int>v;
            for(int j=i;j<=lastInd;j++)
            {
                v.push_back(nums[j]);
                s.insert(v);                
            }
        }

        return s.size();
    }
};