class Solution {
public:

    int wavi(int num1) {
        string s = "";
        while (num1) {
            int digit = num1 % 10;
            s.push_back(char('0' + digit));
            num1 /= 10;
        }
        reverse(s.begin(), s.end());

        int n = s.size();
        if (n < 3) return 0;

        int cnt = 0;

        for (int i = 1; i < n - 1; i++) {
            int a = s[i-1] - '0';
            int b = s[i]   - '0';
            int c = s[i+1] - '0';

            if (b > a && b > c) cnt++;    
            if (b < a && b < c) cnt++;     
        }
        return cnt;
    }
    
    int totalWaviness(int num1, int num2) {
        int cnt = 0;
        for (int i = num1; i <= num2; i++) {
            cnt += wavi(i);
        }
        return cnt;
    }
};