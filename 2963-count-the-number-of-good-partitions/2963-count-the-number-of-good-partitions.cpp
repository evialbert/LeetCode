class Solution {
public:
    #define ll long long
    ll m=1e9+7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>last;
        for(int i=0;i<n;i++){
            last[nums[i]]=i;
        }
        int c=1,s=0,e=last[nums[0]];
        for(int i=1;i<n;i++){
            if(i>e){
                c++;
                s=i;
                e=last[nums[i]];
            }
            else{
                e=max(e,last[nums[i]]);
            }
        }
        ll ans=1;
        for(int i=1;i<=(c-1);i++){
            ans=(ans%m*2)%m;
        }
        return ans;
    }
};