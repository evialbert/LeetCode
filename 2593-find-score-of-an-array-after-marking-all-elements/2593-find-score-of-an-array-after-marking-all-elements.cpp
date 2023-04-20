class Solution {
public:
    struct cmp{
        bool  operator()(vector<int>&a,vector<int>&b)
        {
            if(a[0]==b[0])
                return a[1]<b[1];
            return a[0]<b[0];
        }
    };
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ds;
        for(int i=0;i<n;i++){
            ds.push_back({nums[i],i,0});
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[i]=0;
        }
        long long ans=0;
        sort(ds.begin(),ds.end(),cmp());
        for(int i=0;i<n;i++)
        {
            if(mp[ds[i][1]]==0)
            {
                int var=ds[i][0];
                int index=ds[i][1];
                if(index-1>=0){
                    mp[index-1]=1;
                }
                if(index+1<n){
                    mp[index+1]=1;
                }
                ans+=var;
            }
            
        }
        return ans;
    }
};