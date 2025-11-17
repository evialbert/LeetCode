class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;

        // find the first 1
        while(i < n && nums[i] == 0){
            i++;
        }

        // check all subsequent 1s
        for(int j = i + 1; j < n; j++){
            if(nums[j] == 1){
                if((j - i) <= k) return false;
                i = j;
            }
        }
        return true;
    }
};