class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int c=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<=nums[i]&&c==0){
                continue;
            }
            else{
                c=1;
                break;
            }
        }
        
        if(c==0)
            return true;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>=nums[i]&&c==1){
                continue;
            }
            else{
                return false;
            }
        }
        
        return true;
        
        
    }
};