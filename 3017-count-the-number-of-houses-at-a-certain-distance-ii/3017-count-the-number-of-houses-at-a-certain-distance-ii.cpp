class Solution {
public:   
vector<long long> countOfPairs(int n, int x, int y) {
        if (x > y) swap(x, y);
        vector<long long> A(n);
        for (int i = 1; i <= n; ++i) {
            A[0] += 2;                               // go left and right
            A[min(i - 1, abs(i - y) + x)]--;         // reach 1 then stop
            A[min(n - i, abs(i - x) + 1 + n - y)]--; // reach n then stop
            A[min(abs(i - x), abs(y - i) + 1)]++;    // reach x then split
            A[min(abs(i - x) + 1, abs(y - i))]++;    // reach y then split
            int r = max(x - i, 0) + max(i - y, 0);
            A[r + (y - x + 0) / 2]--;                // i -> x -> y <- x
            A[r + (y - x + 1) / 2]--;                // i -> y -> x <- y
        }
        for (int i = 1; i < n; ++i)
            A[i] += A[i - 1];
        return A;
    }
};


