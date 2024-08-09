class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int al=0,bob=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<10)
                al+=nums[i];
            
            else bob+=nums[i];
        }
        if(al == bob) return false;

        return true;        
    }
};