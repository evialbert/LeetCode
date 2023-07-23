class Solution {
	// generate next k-symmetric number from current number x
    string genKsym(string x, int k) {
        int N = x.size();
        for (int i = N/2; i < N; i++) {
            if (x[i]-'0' < k-1) {
                x[i] = x[N+(~i)] = static_cast<char>(x[i]+1); // i and (N+(~i)) are center-symmetric indices.
                for (int j = N/2; j < i; j++) x[j] = x[N+(~j)] = '0'; // set inner bits to zero
                return x;
            }
        }
        string res = "1" + string(N-1, '0') + "1"; // extend one bit and reset
        return res;
    }
	// transform base k string to decimal long long
    long long baseKtoDeci(string x, long long k) {
        long long res = 0;
        int N = x.size();
        for (long long i = N-1, multp = 1; ~i; i--, multp *= k) {
            res += multp * (x[i]-'0');
        }
        return res;
    }
	// check if num is 10-symmetric
    bool isDeciSym(long long num) {
        string s;
        while (num) {
            char c = num % 10;
            s += c;
            num /= 10;
        }
        int N = s.size();
        for (int i = 0, j = N-1; i < j; i++, j--) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
public:
    long long kMirror(int k, int n) {
        long long res = 0;
        
        string x = "0";
        while (n--) {
            while (true) {
                x = genKsym(x, k);
                long long val = baseKtoDeci(x, k);
                if (isDeciSym(val)) {
                    res += val;
                    break;
                }
            }
        }
        
        return res;
    }
};