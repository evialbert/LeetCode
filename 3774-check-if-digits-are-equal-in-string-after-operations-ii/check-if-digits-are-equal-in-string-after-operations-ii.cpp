class Solution {
public:
    void factorize(int x, int &rem, int &cnt2, int &cnt5) {
        cnt2 = cnt5 = 0;
        rem = x;
        while(rem % 2 == 0 && rem > 0) {
            cnt2++;
            rem /= 2;
        }
        while(rem % 5 == 0 && rem > 0) {
            cnt5++;
            rem /= 5;
        }
        rem %= 10;
    }
    
    int modInverse(int x) {
        if(x == 1) return 1;
        if(x == 3) return 7;
        if(x == 7) return 3;
        if(x == 9) return 9;
        return 1;
    }
    
    bool hasSameDigits(string s) {
        int n = s.size();
        if(n == 2) return (s[0]-'0') == (s[1]-'0');
        int operations = n - 2;
        int N = operations;
        int left = (1 * (s[0]-'0')) % 10, right = (1 * (s[1]-'0')) % 10;
        int f_val = 1, count2 = 0, count5 = 0, coef = 1;
        for(int i = 0; i < operations; i++){
            int num = N - i;
            int den = i + 1;
            int num_rem, num2, num5;
            factorize(num, num_rem, num2, num5);
            f_val = (f_val * (num_rem % 10)) % 10;
            count2 += num2;
            count5 += num5;
            int den_rem, den2, den5;
            factorize(den, den_rem, den2, den5);
            int inv = modInverse(den_rem);
            f_val = (f_val * inv) % 10;
            count2 -= den2;
            count5 -= den5;
            if(count2 >= 1 && count5 >= 1)
                coef = 0;
            else if(count2 > 0) {
                int r = count2 % 4;
                int pow2 = (r == 0) ? 6 : (r == 1) ? 2 : (r == 2) ? 4 : 8;
                coef = (f_val * pow2) % 10;
            } else if(count5 > 0) {
                coef = (f_val * 5) % 10;
            } else {
                coef = f_val;
            }
            left = (left + coef * ((s[i+1]-'0'))) % 10;
            right = (right + coef * ((s[i+2]-'0'))) % 10;
        }
        return left % 10 == right % 10;
    }
};