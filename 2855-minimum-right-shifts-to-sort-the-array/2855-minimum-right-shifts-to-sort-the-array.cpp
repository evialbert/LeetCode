class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
       int n = nums.size();
    vector<int> sortedNums(nums);
    sort(sortedNums.begin(), sortedNums.end());
    
    for (int shift = 0; shift < n; ++shift) {
        bool possible = true;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != sortedNums[(i + shift) % n]) {
                possible = false;
                break;
            }
        }
        if (possible) {
            return shift;
        }
    }
    
    return -1;
    }
};