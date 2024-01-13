class Solution {
public:
    public:
    unordered_map<long long, int> cache;
    string s;
    int k;

    int maxPartitionsAfterOperations(string s, int k) {
        this->s = s;
        this->k = k;
        return dp(0, 0, true) + 1;
    }

private:
    int dp(long long index, long long currentSet, bool canChange) {
        long long key = (index << 27) | (currentSet << 1) | canChange;

        if (cache.count(key)) {
            return cache[key];
        }

        if (index == s.size()) {
            return 0;
        }

        int characterIndex = s[index] - 'a';
        int currentSetUpdated = currentSet | (1 << characterIndex);
        int distinctCount = __builtin_popcount(currentSetUpdated);

        int result;
        if (distinctCount > k) {
            result = 1 + dp(index + 1, 1 << characterIndex, canChange);
        } else {
            result = dp(index + 1, currentSetUpdated, canChange);
        }

        if (canChange) {
            for (int newCharacterIndex = 0; newCharacterIndex < 26; ++newCharacterIndex) {
                int newSet = currentSet | (1 << newCharacterIndex);
                int newDistinctCount = __builtin_popcount(newSet);

                if (newDistinctCount > k) {
                    result = max(result, 1 + dp(index + 1, 1 << newCharacterIndex, false));
                } else {
                    result = max(result, dp(index + 1, newSet, false));
                }
            }
        }

        cache[key] = result;
        return result;
    }
};