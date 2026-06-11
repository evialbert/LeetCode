class Solution {
    #define ll long long
public:
    long long minArraySum(vector<int>& nums) {
        ll n = nums.size(), ans = 0;
        map<ll, ll> mp;
        for(int i=0; i<n; i++) mp[nums[i]]++;
        for(ll i=0; i<n; i++) {
            ll mn = LLONG_MAX;
            if(mp.count(1)) mn = 1;
            for(ll j=2; j*j<=nums[i]; j++) {
                if(nums[i] % j == 0) {
                    if(mp.count(j)) mn = min(mn, j);
                    if(mp.count(nums[i]/j)) mn = min(mn, nums[i]/j);
                }
            }
            if(mn == LLONG_MAX) ans += nums[i];
            else ans += mn;
        }
        return ans;
    }
};