class Solution {
public:
    int climbStairs(int n) {
        vector<int> fibo = {1,1};
        if(n<2) return fibo[n];
        for(int i=2;i<=n;i++) fibo.push_back(fibo[i-1]+fibo[i-2]);
        return fibo.back();
    }
};