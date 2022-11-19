class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> ans;
        for (int q : queries) {
            ans.push_back(get(q, intLength));
        }
        return ans;
    }
    
    long long get(int q, int l) {
        if (l==1) return q<10 ? q : -1;
        
        long long temp = pow(10, l)/pow(10, l/2 + 1);;
        long long ans;
        
        temp += q-1;  
        
        ans = mirror(temp, l);
        if (ans>=pow(10, l)) return -1;
        return ans;
    }
    
    long long mirror(long long n, int len) {
        int c = len/2;
        auto tmp = n;
        auto rev = 0;
        if(len%2 != 0) tmp/=10;
        while (c--) {
            n*=10;
            n+=tmp%10;
            tmp/=10;
        }
        return n;
    }
};