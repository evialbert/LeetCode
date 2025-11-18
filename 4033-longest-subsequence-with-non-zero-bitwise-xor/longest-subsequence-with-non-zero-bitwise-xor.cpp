class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorInt = nums[0];
        int el = nums[0];
        bool allsame = true;
        for(int i=1;i<nums.size();i++){
            xorInt = xorInt^nums[i];
            if(nums[i]!=el)allsame=false;
        }
        if(xorInt!=0)return nums.size();
        if(allsame){
            if(nums.size()%2==0 && el!=0)return nums.size()-1;
            return 0;
        }
        return nums.size()-1;
    }
};