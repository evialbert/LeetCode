class Solution {
public:
    int minChanges(int n, int k) {
        
        if(n == k)
            return 0;

        int ops = 0;

        while(n)
        {
            int a = n % 2;
            int b = k % 2;

            n = n >> 1;
            k = k >> 1;

            if(a == 0 && b == 1)
                return -1;

            if(a == 1 && b == 0)
                ops++;
        }    

        if(k > 0)
            return -1;

        return ops;
    }
};