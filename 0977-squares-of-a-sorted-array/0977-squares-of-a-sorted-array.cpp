class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>res(nums.size());
        int l=0,r=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(abs(nums[r])>abs(nums[l]))
            {
                res[i]=nums[r]*nums[r];
                r--;
            }
            else
            {
                res[i]=nums[l]*nums[l];
                l++;
            }
        }
        return res;
    }
};