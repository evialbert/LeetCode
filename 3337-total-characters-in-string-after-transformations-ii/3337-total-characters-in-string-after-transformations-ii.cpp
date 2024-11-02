class Solution {
public:
    vector<vector<long long>> multiplyMatrix(const vector<vector<long long>>& A, const vector<vector<long long>>& B, int MOD) {
        int n = A.size();
        vector<vector<long long>> C(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
        return C;
    }

    vector<vector<long long>> matrixExponentiation(vector<vector<long long>> base, int exp, int MOD) {
        int n = base.size();
        vector<vector<long long>> result(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) result[i][i] = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = multiplyMatrix(result, base, MOD);
            base = multiplyMatrix(base, base, MOD);
            exp /= 2;
        }
        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        const int MOD = 1e9 + 7;
        vector<long long> a(26, 0);
        for (char c : s)
            a[c - 'a']++;

        vector<vector<long long>> b(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                b[i][(i + j) % 26] = 1;
            }
        }

        b = matrixExponentiation(b, t, MOD);
        vector<long long> c(26, 0);
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                c[i] = (c[i] + a[j] * b[j][i]) % MOD;

        long long result = 0;
        for (int i = 0; i < 26; ++i)
            result = (result + c[i]) % MOD;

        return result;
    }
};
