class Solution {
public:
    const int mod = 1e9 + 7;
    
    int countEffective(vector<int>& nums) {
        int total_or = 0;
        for(auto it: nums) {
            total_or |= it;
        }

        int cb = log2(total_or);

        int bits = (1 << cb);

        if(bits < total_or) {
            bits *= 2;
        }


        int n = nums.size();

        vector<int> mods(n + 1);
        mods[0] = 1;
        cout << 1 << " ";
        for(int i = 1; i <= n; i ++) {
            mods[i] = (2LL * mods[i - 1]) % mod;
        }


        // classic SOS
        vector<int> freq(2 * bits);

        for(auto it: nums) {
            freq[it] ++;
        }


        for(int i = 0; i <= 20; i ++) {
            for(int m = 0; m < bits; m ++) {
                if(m & (1 << i)) {
                    freq[m] += freq[m ^ (1 << i)];
                }
            }
        }

        // all of these frequencies -  2 ^ freq[i] are possible answers but there are overlaps to remove them apply reverse SOS again. 

        for(int i = 0; i < bits; i ++) {
            freq[i] = mods[freq[i]] - 1;
        }

        // reverse SOS
        for(int i = 0; i <= 20; i ++) {
            for(int m = 0; m < bits; m ++) {
                if(m & (1 << i)) {
                    freq[m] -= freq[m ^ (1 << i)];
                    freq[m] += mod;
                    freq[m] %= mod;
                }
            }
        }

        int ans = 1;
        
        for(int i = 0; i < total_or; i ++) {
            ans += freq[i];
            ans %= mod;
        }
        return ans;
    }
};