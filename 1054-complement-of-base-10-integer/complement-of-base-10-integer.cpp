class Solution {
public:
    int bitwiseComplement(int n) {
        return (n==0)?1:n^((1<<(32-countl_zero((unsigned)n)))-1);
    }
};