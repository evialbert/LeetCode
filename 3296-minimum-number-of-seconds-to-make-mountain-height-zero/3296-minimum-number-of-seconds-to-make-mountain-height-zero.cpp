class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long lo = 0, hi = 1e18, mid;
        while(hi-lo > 1){
            mid = (hi+lo)/2;
            long long cnt = 0;
            for(auto it: workerTimes){
                long long p = sqrtl(2LL * mid / (it*1LL));
                while(p + p*p > (2LL*mid / (it*1LL))) p--;
                cnt += p;
            }

            if(cnt >= mountainHeight) hi = mid;
            else lo = mid;
        }

        return hi;
    }
};