class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n =nums.size();
        vector<long long > pre(n , 0);
        pre[0]= nums[0];

        for(int i =1 ; i < n ; i++){
            pre[i] = nums[i]+pre[i-1];
        }

        long long  sum= pre[n-1];
        if(sum % p ==0){
            return 0;
        }

        long long  target = sum % p;

        unordered_map<long long ,long long > mp;
        mp.insert({0 , -1});
        long long  mn = 1e6;
        for(int i = 0 ;  i < n;i++){

            if( mp.find( ((pre[i] - target + p ))%p )  != mp.end()){
                mn = min(mn ,1LL * i - mp[ ((pre[i] - target + p ))%p] );
            }
            mp[pre[i]%p]=i;
        }

        return (mn==nums.size()|| sum < p) ? -1 : mn;
    }
};