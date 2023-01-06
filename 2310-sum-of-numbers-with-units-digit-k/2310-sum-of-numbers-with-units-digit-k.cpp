class Solution {
public:
    int minimumNumbers(int n, int k) {
        if(n == 0) return 0;
        for(int i = 1; i <= 10; i++) {
            if(k * i > n) break;
            if((k * i) % 10 == n % 10) return i;
        }
        return -1;
    }
};