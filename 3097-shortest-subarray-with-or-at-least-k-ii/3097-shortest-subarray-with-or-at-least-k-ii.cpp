class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> hash(31,0);
        int n = nums.size();
        int i=0,j=0;
        int ans = n+1;
        int mask = 0;
        int val,cnt;
        while(i<n) {
            mask |= nums[i];
            val = nums[i];
            cnt = 0;
            while(val) {
                if(val&1) hash[cnt]++;
                cnt++;
                val = val>>1;
            }
            if(mask>=k) {
                while(j<=i && mask>=k) {
                    val = nums[j];
                    cnt = 0;
                    while(val) {
                        if(val&1) {
                            hash[cnt]--;
                            if(hash[cnt]==0) {
                                mask ^= (1<<cnt);
                            }
                        }
                        cnt++;
                        val = val>>1;
                    }
                    j++;
                }
                ans = min(ans,i-j+2);
            }
            i++;
        }
        if(ans==n+1) ans = -1;
        return ans;
    }
};