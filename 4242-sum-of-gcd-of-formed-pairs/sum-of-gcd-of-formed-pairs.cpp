class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);

        int maxi = -1;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);

            prefixGcd[i] = gcd(maxi, nums[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int i = 0;
        int j = n - 1;
        long long sum = 0;
        while (i < j) {
            sum += (long long)(gcd(prefixGcd[i++], prefixGcd[j--]));
        }
        return sum;
    }
};