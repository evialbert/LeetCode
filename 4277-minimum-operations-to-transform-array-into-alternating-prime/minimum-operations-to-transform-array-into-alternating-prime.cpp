class Solution {
public:
    bool isprime(int n) {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i += 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        return true;
    }

    int minOperations(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0 && isprime(nums[i])) {
                continue;
            } else if (i % 2 == 0 && !isprime(nums[i])) {
                int x = nums[i];
                while (!isprime(x)) {
                    x++;
                    cnt++;
                }

            } else if (i % 2 != 0 && !isprime(nums[i])) {
                continue;
            } else if (i % 2 != 0 && isprime(nums[i])) {
                int y = nums[i];
                while (isprime(y)) {
                    y++;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};