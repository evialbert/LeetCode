class Solution {
public:
    string maxSumOfSquares(int len, int sum) {
        if (sum > len * 9) return "";

        std::string res(len, '0');
        for (int i = 0; i < len && sum > 0; i++) {
            if (sum >= 9) {
                res[i] = '9';
                sum -= 9;
            }
            else {
                res[i] = '0' + sum;
                sum = 0;
            }
        }
        if (sum) return "";
        return res;
    }
};