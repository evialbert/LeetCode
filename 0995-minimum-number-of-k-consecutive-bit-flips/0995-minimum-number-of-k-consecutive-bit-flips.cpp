class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int ans = 0;

        int i = 0, j = 0;
        int n = nums.size();
        vector<int> reset(n,0);
        
        int flag = 1;
        while(i<=(n-k)){
            flag = flag^reset[i];
            if(nums[i]^flag){
                ans++;
                if(i+k<n){
                    reset[i+k] = 1;
                }
                flag = !flag;
            }
            i++;
        }

        while(i<n){
            flag = flag^reset[i];
            if(nums[i]^flag){
                return -1;
            }
            i++;
        }

        return ans;
    }
};