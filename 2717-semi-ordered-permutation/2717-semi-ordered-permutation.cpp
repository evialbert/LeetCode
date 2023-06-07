class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int minIdx{0};
        int maxIdx{0};
        for(int i=0; i<nums.size(); i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;
            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }
        int res{0};
        res += minIdx;
        res += nums.size()-1-maxIdx-(maxIdx<minIdx);
        return res;
    }
};