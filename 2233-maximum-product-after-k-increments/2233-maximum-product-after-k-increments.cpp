class Solution {
public:
    typedef long long ll;
    int maximumProduct(vector<int>& nums, int k) {
        multiset<ll> st; 
        for(int x : nums) st.insert((ll)x);
        while(k--){
            auto it = st.begin(); 
            ll x = *it;
			// increasing the smallest element by 1
            st.erase(it);
            st.insert(x+1);
        }
        ll ans = 1;
        ll mod = 1e9+7;
        for(auto x : st){
            ans *= x;
            ans %= mod;
        }
        return ans;
    }
};