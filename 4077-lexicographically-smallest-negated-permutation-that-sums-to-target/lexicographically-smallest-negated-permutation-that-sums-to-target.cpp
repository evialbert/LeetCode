class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target){
        long long S = 1LL*n*(n+1)/2;
        // Feasibility check: sum must be reachable and parity must match
        if (llabs(target) > S || ((S - target) & 1)) return {};
        // total absolute value to flip negative
        long long rem = (S - target) / 2;  
        vector<int> ans; ans.reserve(n);
        vector<char> used(n+1, 1);
        // Greedily pick largest numbers to negate for lexicographically smallest array
        for (int k = n; k > 0 && rem > 0; --k) {  
            if (rem >= k) { ans.push_back(-k); used[k] = 0; rem -= k; }
            else { ans.push_back(-(int)rem); used[rem] = 0; rem = 0; }
        }
        // Append remaining positive values in increasing order
        for (int i = 1; i <= n; ++i) if (used[i]) ans.push_back(i);
        return ans;
    }
};