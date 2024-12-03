class Solution {
public:
    int smallestNumber(int n) {
        int nRes = 1;
        while (nRes <= n) nRes *= 2;
        return nRes - 1;
    }
};