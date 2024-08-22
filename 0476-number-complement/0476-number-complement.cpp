class Solution {
public:
    int findComplement(int num) {
        long int n = (int)log2(num)+1;
        n = 1<<n;
        n = n-1;
        return num^n;
    }
};