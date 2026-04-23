class Solution {
    inline static long long dp[96000];
    inline static bool ok[150];
    inline static bool init = false;

    static void Init() {
        if (init) return;
        
        for (int i = 1; i <= 149; i++) {
            if (i < 10) ok[i] = true;
            else if (i < 100) ok[i] = (i / 10) != (i % 10);
            else {
                int a = i / 100, b = (i / 10) % 10, c = i % 10;
                ok[i] = (a < b && b < c) || (a > b && b > c);
            }
        }
        
        for (int l = 0; l <= 9; l++) {
            for (int t = 0; t <= 3; t++) {
                for (int s = 0; s <= 149; s++) {
                    if (t != 3 || ok[s]) dp[l * 600 + t * 150 + s] = 1;
                }
            }
        }
        
        for (int r = 1; r <= 15; r++) {
            int ro = r * 6000, pro = (r - 1) * 6000;
            for (int l = 0; l <= 9; l++) {
                int lo = l * 600;
                for (int t = 0; t <= 3; t++) {
                    int to = t * 150;
                    for (int s = 0; s <= 140; s++) {
                        long long sum = 0;
                        for (int d = 0; d <= 9; d++) {
                            int nt = t;
                            if (t == 0) {
                                if (d > l) nt = 1;
                                else if (d < l) nt = 2;
                                else nt = 3;
                            } else if (t == 1) {
                                if (d <= l) nt = 3;
                            } else if (t == 2) {
                                if (d >= l) nt = 3;
                            }
                            sum += dp[pro + d * 600 + nt * 150 + s + d];
                        }
                        dp[ro + lo + to + s] = sum;
                    }
                }
            }
        }
        
        init = true;
    }

    long long Solve(long long n) {
        if (n == 0) return 0;
        int d[20];
        int len = 0;
        while (n > 0) {
            d[len++] = (int)(n % 10);
            n /= 10;
        }
        
        long long ans = 0;
        for (int i = 1; i < len; i++) {
            int ro = (i - 1) * 6000;
            for (int v = 1; v <= 9; v++) {
                ans += dp[ro + v * 600 + v];
            }
        }
        
        int t = 0, s = 0, last = 0;
        
        for (int i = len - 1; i >= 0; i--) {
            int lim = d[i];
            int st = (i == len - 1) ? 1 : 0;
            int ro = i * 6000;
            
            for (int v = st; v < lim; v++) {
                if (i == len - 1) {
                    ans += dp[ro + v * 600 + v];
                } else {
                    int nt = t;
                    if (t == 0) {
                        if (v > last) nt = 1;
                        else if (v < last) nt = 2;
                        else nt = 3;
                    } else if (t == 1) {
                        if (v <= last) nt = 3;
                    } else if (t == 2) {
                        if (v >= last) nt = 3;
                    }
                    ans += dp[ro + v * 600 + nt * 150 + s + v];
                }
            }
            
            if (i == len - 1) {
                t = 0;
            } else {
                if (t == 0) {
                    if (lim > last) t = 1;
                    else if (lim < last) t = 2;
                    else t = 3;
                } else if (t == 1) {
                    if (lim <= last) t = 3;
                } else if (t == 2) {
                    if (lim >= last) t = 3;
                }
            }
            s += lim;
            last = lim;
        }
        
        if (t != 3 || ok[s]) ans++;
        
        return ans;
    }

public:
    long long countFancy(long long l, long long r) {
        Init();
        return Solve(r) - Solve(l - 1);
    }
};