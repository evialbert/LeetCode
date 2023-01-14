class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcdv = 0;
        for(auto& i:numsDivide) gcdv = gcd(i,gcdv); 
        sort(nums.begin(), nums.end());
        for(int i =0;i<nums.size() && nums[i]<=gcdv;i++) 
            if(gcdv%nums[i]==0) return i;
        return -1;
    }
};