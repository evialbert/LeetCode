class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        // Edge case for single digit numbers or 10, 100, 1000... etc.
        if (len == 1) {
            return to_string(stoll(n) - 1);
        }

        // List to store the possible candidates
        vector<long long> candidates;

        // Edge cases like "999...9" and "100...001"
        candidates.push_back(pow(10, len - 1) - 1);    // Lower bound (e.g., 999)
        candidates.push_back(pow(10, len) + 1);        // Upper bound (e.g., 1001)

        // Get the first half and generate a few possible palindromes by tweaking the first half
        long long prefix = stoll(n.substr(0, (len + 1) / 2));

        // Generate potential palindromes by mirroring the prefix and adjusting it by -1, 0, +1
        for (long long i = -1; i <= 1; i++) {
            string p = to_string(prefix + i);
            string candidate = p + string(p.rbegin() + (len % 2), p.rend());
            candidates.push_back(stoll(candidate));
        }

        long long original = stoll(n), closest = -1;
        for (long long candidate : candidates) {
            if (candidate != original) {
                if (closest == -1 ||
                    abs(candidate - original) < abs(closest - original) ||
                    (abs(candidate - original) == abs(closest - original) && candidate < closest)) {
                    closest = candidate;
                }
            }
        }

        return to_string(closest);
    }
};