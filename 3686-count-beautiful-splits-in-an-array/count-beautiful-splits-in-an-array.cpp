class Solution {
private:
    vector<long long> hash, power;
    long long MOD = 1e9 + 7;
    int getHash(int l, int r) {
        return (hash[r]-(hash[l]*power[r-l])%MOD+MOD)%MOD;
    }
public:
    int beautifulSplits(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) {
            return 0;
        }
        long long BASE = 31;
        hash.resize(n+1,0);
        power.resize(n+1,0);
        power[0] = 1;
        for(int i=1; i<=n; i++) {
            hash[i] = (hash[i-1]*BASE + nums[i-1])%MOD;
            power[i] = (power[i-1]*BASE)%MOD;
        }
        int count = 0;
        for(int i=1; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                int len1 = i, len2 = j-i, len3 = n-j;
                bool condition1 = (len2>=len1) && (getHash(0, len1) == getHash(i, i+len1));
                bool condition2 = (len3>=len2) && (getHash(i, j) == getHash(j, j+len2));
                if(condition1 || condition2) {
                    count++;
                }
            }
        }
        return count;
    }
};