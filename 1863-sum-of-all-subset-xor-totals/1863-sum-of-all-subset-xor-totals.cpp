class Solution {
public:
    
    int dfs(vector<int>& nums, int i, int n, int xorr)
    {
        // base case
        
        if(i == n)
        {
            return xorr;
        }
        
        // exclude the curr element
        
        int exc = dfs(nums, i + 1, n, xorr);
        
        // include the curr element
       
        int inc = dfs(nums, i + 1, n, xorr ^ nums[i]);
        
        // return total
        
        return inc + exc;
    }
    
    int subsetXORSum(vector<int>& nums) {
        
        int n = nums.size();
        
        return dfs(nums, 0, n, 0);
    }
};