class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1,i=0;
        for(i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                break;
            }
        }
        if(target>=nums[0]){
            e=i;
        }
        else{
            s=i+1;
        }
        while(s<=e){
            int m=(s+e)/2;
            if(nums[m]==target) return true;
            else if(nums[m]>target) e=m-1;
            else s=m+1;
        }
        return false;
    }
};