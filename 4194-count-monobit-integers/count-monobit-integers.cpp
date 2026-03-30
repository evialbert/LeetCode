class Solution {
public:
    int countMonobit(unsigned n) {
        return 1+log2(n+1);
    }
};