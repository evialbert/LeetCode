class Solution {
public:
    
    void dfs(vector<int> &nums, int index, int &maxi, int val ,int &count)
    {
        if(index == nums.size()){
            if(val >= maxi){
                maxi = val;
                count++;
            }
            return;
        }
        dfs(nums, index + 1, maxi, val | nums[index], count);
        dfs(nums, index + 1, maxi, val, count);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = INT_MIN;
        int count = 0;
        dfs(nums, 0 , maxi, 0, count);
        return count;
    }
};