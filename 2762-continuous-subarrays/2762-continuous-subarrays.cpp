class Solution {
public:
    int findmax(map<int,int>mp){
        int x=0;
        for(auto it:mp)x=max(x,it.first);
        return x;
    }
    int findmin(map<int,int>mp){
        int x=1e9;
        for(auto it:mp)x=min(x,it.first);
        return x;
    }
    long long continuousSubarrays(vector<int>& nums) {
        map<int,int>mp;
        long long ans=0;
        int i=0,j=0;
        int n=nums.size();
        while(j<n){
            mp[nums[j]]++;
            int maxi=findmax(mp);
            int mini=findmin(mp);
            if(abs(maxi-mini)<=2)ans+=j-i+1;
            else {
                while(maxi-mini>2){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0)mp.erase(nums[i]);
                    i++;
                  maxi=findmax(mp);
                  mini=findmin(mp);
                }
                ans+=j-i+1;
            }
            j++;
        }
        return ans;
    }
};