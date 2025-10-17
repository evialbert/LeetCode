class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int sumand=nums[0];
        for(int i=0;i<n;i++){
            sumand&=nums[i];
        }
        bool equal=true;
        for(int i=0;i<n;i++){
            if(nums[i]!=sumand){
                equal=false;
                break;
            }
        }
        if(equal) return 0;
        return 1;
    }
};