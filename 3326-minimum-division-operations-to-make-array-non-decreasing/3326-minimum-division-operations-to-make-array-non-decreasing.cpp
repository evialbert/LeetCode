class Solution {
   
int greatest_proper_divisors(int x) {
        if (x <= 1) return 1;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return x / i;  
            }
        }
        return 1;  
    }
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 0;

        int operations = 0;
        int small = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {

            int gcd ;
           gcd= greatest_proper_divisors(nums[i]);
            while (nums[i] > small) {
                if (gcd == 1) {
                    return -1; // Invalid case if GPD is 1
                }

                // Divide by the GPD
                nums[i] /= gcd;
                operations++;

               
                if (nums[i] <= small) {
                    break; // Exit if we've reduced it enough
                }
            
           gcd= greatest_proper_divisors(nums[i]);
           }
            small = min(nums[i], small);
        }

        return operations;
    }
};