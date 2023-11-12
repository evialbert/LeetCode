class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int res(0),len = nums.size();
        
        for(int i = 0; i < len; i++){
            res = max(res,nums[i] ^ nums[i]);
            
            for(int j = i+1; j < len; j++){
                if(abs(nums[i] - nums[j]) <= min(nums[i],nums[j])){
                    res = max(res,nums[j] ^ nums[i]);
                }
            }
        }
        
        return res;
    }
};