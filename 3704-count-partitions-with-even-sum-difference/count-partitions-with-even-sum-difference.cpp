class Solution {
public:
    int countPartitions(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int count=0;
        long long right = accumulate(nums.begin(),nums.end(),0LL);
        long long left = 0;
        for(int i=0;i<nums.size()-1;i++){
            left+=nums[i];
            right-=nums[i];
            if(abs(left-right)%2==0){
                count++;
            }
        }
        return count;
    }
};