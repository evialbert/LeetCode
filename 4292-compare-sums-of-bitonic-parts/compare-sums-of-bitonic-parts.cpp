class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long int sumA=0, sumD=0;
        int flag=0;
        for(int i=0; i<nums.size(); i++){
            if(i!=nums.size()-1){
                if(nums[i]>nums[i+1]&&flag==0){
                    sumA+=nums[i];
                    flag=1;
                }
            }
            if(flag==0) sumA+=nums[i];
            else sumD+=nums[i];
        }
        if(sumA==sumD) return -1;
        else if(sumA>sumD) return 0;
        return 1;
    }
};