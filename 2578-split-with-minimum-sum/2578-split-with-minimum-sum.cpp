class Solution {
public:
    int splitNum(int num) {
        int num1 = 0, num2 = 0;
        string s = to_string(num);
        sort(s.begin(), s.end());
        for(int i = 0; i < s.length(); i++) {
            if(i % 2) {
                num1 = num1 * 10 + s[i] - '0';
            } else {
                num2 = num2 * 10 + s[i] - '0';
            }
        }
        return num1 + num2;
    }
};