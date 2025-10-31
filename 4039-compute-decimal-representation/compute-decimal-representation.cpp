class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        long long temp = n;

        long long power = 10;
        while(temp > 0) {
            long long digit = temp % power;
            if (digit) {
                temp -= digit;
                ans.push_back(digit);
            }
            power *= 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};