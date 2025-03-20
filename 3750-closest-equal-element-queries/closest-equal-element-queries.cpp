class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>>mp;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        vector<int>ans(queries.size());
        for(int i=0;i<queries.size();i++){
                int mn =INT_MAX;
                // vector<int>temp = mp[nums[queries[i]]];
            int l = 0, r = mp[nums[queries[i]]].size()-1,x=0;
            while(l<=r){
                int mid = (l+r)/2;
                if(mp[nums[queries[i]]][mid]==queries[i]){
                    x= mid;
                    break;
                }else if(mp[nums[queries[i]]][mid]<queries[i]){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }

            int len = mp[nums[queries[i]]].size();

            if( mp[nums[queries[i]]].size()>1){
                int left = (x-1+len)%len;
                int right = (x+1+len)%len;
                if(x-1>=0){
                    mn = min(abs(queries[i]-mp[nums[queries[i]]][left]),min(mn,n-(queries[i]-mp[nums[queries[i]]][left])));
                }else{
                    mn = min(abs(mp[nums[queries[i]]][left]-queries[i]),min(mn,abs(n-(mp[nums[queries[i]]][left]-queries[i]))));
                }
                if(x+1<len){
                    mn = min(abs(mp[nums[queries[i]]][right]-queries[i]),min(mn,abs(n-(mp[nums[queries[i]]][right]-queries[i]))));
                }else{
                    mn = min(abs(queries[i]-mp[nums[queries[i]]][right]),min(mn,abs(n-(queries[i]-mp[nums[queries[i]]][right]))));
                }
            }
          
            if(mn!=INT_MAX)
            ans[i]=(mn);
            else
           ans[i]=-1;
            
        }
        return ans;
    }
};