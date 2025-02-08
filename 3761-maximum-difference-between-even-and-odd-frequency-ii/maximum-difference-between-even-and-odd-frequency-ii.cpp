class Solution {
public:
    int maxDifference(const string& s, int k) {
        const int L = s.length();
        // preflen_2_dig_2_count[j][d] - preflen_2_dig_2_count[i][d] = count of digit d in s(i,j]
        vector<Dig2CountT> preflen_2_dig_2_count(L + 1);
        for (int i = 0; i < L; ++i) {
            for (int d = 0; d < kDigEnd; ++d)
                preflen_2_dig_2_count[i + 1][d] = preflen_2_dig_2_count[i][d];
            ++preflen_2_dig_2_count[i + 1][s[i] - kDigBeg];
        }

        int res = -kInf;

        // For each pair of digits (a,b), maintain max count diff broken down per parities: odd/even
        int parab2maxdiff[kParitySize][kParitySize];
        for (int a = 0; a < kDigEnd; ++a) { // Try all pairs of digits
            for (int b = 0; b < kDigEnd; ++b) if (a != b) {
                for (int pa = 0; pa < kParitySize; ++pa)
                    for (int pb = 0; pb < kParitySize; ++pb)
                        parab2maxdiff[pa][pb] = -kInf;

                // Sliding window right -> left
                // For each start position i, find all valid end positions j where:
                // 1. length ≥ k (j-i > k)
                // 2. even count of b should not be 0; count of a is odd => never 0
                for (int i = L - k, j = L + 1; ~i; --i) {
                    while (j - i > k && preflen_2_dig_2_count[j - 1][b] > preflen_2_dig_2_count[i][b]) {
                        --j;
                        int pa = preflen_2_dig_2_count[j][a] & 1;
                        int pb = preflen_2_dig_2_count[j][b] & 1;
                        parab2maxdiff[pa][pb] = max(
                            parab2maxdiff[pa][pb],
                            preflen_2_dig_2_count[j][a] - preflen_2_dig_2_count[j][b]);
                    }
                    int pa = preflen_2_dig_2_count[i][a] & 1;
                    int pb = preflen_2_dig_2_count[i][b] & 1;
                    res = max(
                        res,
                        parab2maxdiff[pa ^ 1][pb] - // char a: opposite parity (pa^1) of current
                            (preflen_2_dig_2_count[i][a] - preflen_2_dig_2_count[i][b]));
                }
            }
        }

        return res;
    }

private:
    static constexpr int kInf = numeric_limits<int>::max() / 3;
    static constexpr char kDigBeg = '0';
    static constexpr int kDigEnd = 5;     // Digits are 0-4
    static constexpr int kParitySize = 2; // 0=even, 1=odd

    using Dig2CountT = array<int, kDigEnd>;
};