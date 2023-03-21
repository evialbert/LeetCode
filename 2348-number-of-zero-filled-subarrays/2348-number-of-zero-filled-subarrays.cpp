class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long a = 0;
        long long b = 0;
        for(int i = 0 ;i<nums.size();i++){
            if(nums[i]==0)b = b+1;
            else{
                a = ((b*(b+1))/2 )+a;
                b=0;
            }
        }
        a = ((b*(b+1))/2)+a;
        return a;
        
    }
};