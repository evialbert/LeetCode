class Solution {
public:
    
    
    int xorBeauty(vector<int>& nums) {
        
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            ans = ans xor nums[i];
        }
        return ans;
    }
};