class Solution {
public:

    int mod = 1e9 + 7;

    long long fact(int n) {
        if (n == 1) return 1;
        return (n*fact(n-1)*1ll)%mod;
    }

    int countPermutations(vector<int>& complexity) {

        for (int i=1;i<complexity.size();i++) {
            if (complexity[0] >= complexity[i]) return 0;
        }

        int n = complexity.size() - 1;

        return fact(n);
        
    }
};