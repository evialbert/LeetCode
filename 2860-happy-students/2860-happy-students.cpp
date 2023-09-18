class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count1=0,count2=0;
        if(nums[0]>0){
            count1++;
        }
        for(int i=0;i<nums.size();i++) {
            count2++;
            if(count2>nums[i]) {
                if(i+1<nums.size() && count2<nums[i+1])
                    count1++; 
                else if(i+1==nums.size()) count1++;
            }
        }
        return count1;
    }
};