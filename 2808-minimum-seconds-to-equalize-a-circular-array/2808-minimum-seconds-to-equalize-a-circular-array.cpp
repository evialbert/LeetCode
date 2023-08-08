class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
         int n=nums.size();
        map<int,int> mp,g;
        map<int,pair<int,int>> f;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                if(g.find(nums[i])!=g.end()){
                    g[nums[i]]=max(g[nums[i]],(i-mp[nums[i]]-1));
                }
                else g[nums[i]]=(i-mp[nums[i]]-1);
            }
            mp[nums[i]]=i;
            if(f.find(nums[i])!=f.end()){
                f[nums[i]]={f[nums[i]].first,i};
            }
            else f[nums[i]]={i,i};
        }
        for(auto k:f){
            g[k.first]=max(g[k.first],(k.second.first+n-1-k.second.second));
        }
        int ans=INT_MAX;
        for(auto k:g){
            if(k.second%2!=0){
                ans=min(ans,k.second/2+1);
            }
            else ans=min(ans,k.second/2);
        }
        return ans;
    }
};