class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int n=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            n+=nums[i];
            if(n==0){
                cnt++;
            }
        }
        return cnt;
    }
};