class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int c=0,b=0;
        for(int i:nums) if(i==0) c++;
        for(int i=(nums.size()-c);i<nums.size();i++) if(nums[i]==0) b++;
        return (c-b);
    }
};