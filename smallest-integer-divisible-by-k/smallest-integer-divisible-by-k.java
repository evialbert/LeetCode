class Solution {
    public int smallestRepunitDivByK(int K) {
        if(K == 1) {
            return 1;
        }
        if(K % 2 == 0 || K % 5 == 0) {
            return -1;
        }
        int a = 1;
        int b = K;
        int c = 1;
        while(b > 0) {
            a = a * 10 + 1;
            if(b == a) {
                c++;
                break;
            }
            b = b / 10;
            c++;
        }
        
        while(a % K != 0) {
            a = (a % K) * 10 + 1;
            c++;
        }
        return c;
    }
}