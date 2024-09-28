class Solution {
public:
    int minElement(vector<int>& nums) {
        int rem = 0, sum = 0, i = 0;
        for(int num : nums)
        {
            while(num > 0)
            {
                rem = num%10;
                sum += rem;
                num /= 10;
            }
            nums[i] = sum;
            ++i;
            sum = 0;
        }
        return *min_element(nums.begin(), nums.end());
    }
};