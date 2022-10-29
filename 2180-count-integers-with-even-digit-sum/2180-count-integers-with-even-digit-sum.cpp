// Time: O(NlgN)
// Space: O(1)
class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        for (int i = 1; i <= num; ++i) {
            int n = i, sum = 0;
            while (n) {
                sum += n % 10;
                n /= 10;
            }
            ans += sum % 2 == 0;
        }
        return ans;
    }
};