class Solution {
public:
    #define ll long long
    ll mod=1e9+7;
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        sort(nums.begin(),nums.end());
        ll sum=0,n=nums.size(),maxi=nums.back()-nums[0],l=nums.back();
        
        for(int i=0;i<n;i++){
            sum +=l-nums[i];
        }

        ll ans=sum*cost1;
        for(ll i=l;i<=2*l;i++){
            if(sum-maxi<maxi){
                ans = min(ans,cost2*(sum-maxi)+ (2*maxi-sum)*cost1);
            } else {
                if((sum&1)) ans=min({ans,cost2*(sum/2) + cost1});
                else ans=min({ans,cost2*(sum/2)});
            }

            sum+=n;maxi++;
        }
        
        return ans%mod;
    }
};