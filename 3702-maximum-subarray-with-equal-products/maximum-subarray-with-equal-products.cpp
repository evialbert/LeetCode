class Solution {
public:
    int maxLength(std::vector<int>& nums) 
    {
        int n = nums.size();
        int maxLen = 0;
        for (int i = 0; i < n; ++i) 
        {
            int currentGCD = nums[i];
            int currentLCM = nums[i];
            double reciprocal = 1.0/nums[i];
            
            for (int j = i; j < n; ++j) 
            {
                if (j > i) 
                {
                    currentGCD = gcd(currentGCD, nums[j]);
                    currentLCM = lcm(currentLCM,nums[j]); 
                    reciprocal /= nums[j];
                }
                if (currentGCD * currentLCM * reciprocal>0.99999999) 
                    maxLen = max(maxLen, j - i + 1);
                
            }
        }
        return maxLen;
    }
};