class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> primes(right+1, true);
        
        for(int i=2;i<=right;i++) {
            if(primes[i] == false) {
                continue;
            }

            for(int p=i;(long)p*i<=right;p++) {
                primes[p*i] = false;
            }
        }

        int pre = -1;
        int min_dif = INT_MAX;
        vector<int> res(2, -1);
        if(left == 1) {
            left++;
        }
        for(int i = left;i<=right;i++) {
            if(!primes[i]) {
                continue;
            }

            if(pre!=-1 && min_dif>i - pre) {
                min_dif = i - pre;
                res[0] = pre;
                res[1] = i;
            }

            pre = i;
        }

        return res;
    }
};