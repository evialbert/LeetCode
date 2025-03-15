class Solution {
public:
    int minimumBuckets(string hamsters) {
        int res = 0;
        int n = hamsters.length();

        if (n == 1) {
            return hamsters[0] == 'H' ? -1 : 0;
        }

        for (int i = 0; i < n; i++) {
            if (hamsters[i] == 'H') {
                if (i > 0 && hamsters[i - 1] == 'b') {
                    continue;
                }
                if (i + 1 < n && hamsters[i + 1] == '.') {
                    hamsters[i + 1] = 'b';
                    res++;
                } else if (i > 0 && hamsters[i - 1] == '.') {
                    hamsters[i - 1] = 'b';
                    res++;
                } else {
                    return -1;
                }
            }
        }

        return res;
    }
};