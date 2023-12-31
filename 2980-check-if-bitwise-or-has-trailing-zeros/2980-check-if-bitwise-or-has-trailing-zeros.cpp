class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)c++;
            if(c>1)return 1;
        }
        return 0;
    }
};