class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int n = nums.size();
        int total = 0;
        for(int i = 0;i<n;i++){
            int flag = 2;
            int temp = i-k;
            int temp2 = i+k;
            if(temp>-1) if(nums[temp]>=nums[i]) flag--;
            if(temp2<n) if(nums[temp2]>=nums[i]) flag--;
            if(flag == 2) total+=nums[i];
        }
        return total;
    }
};