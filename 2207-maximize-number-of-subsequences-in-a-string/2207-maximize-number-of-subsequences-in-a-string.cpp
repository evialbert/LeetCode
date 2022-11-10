class Solution {
public:
    long long cal(string s, string t){
    long long ans = 0;
    unordered_map<char, long long> m;
    for(auto x : s){
        if(x == t[1]){
        ans += m[t[0]];
        }
        m[x]++;
    }
    return ans;
    }
    long long maximumSubsequenceCount(string text, string pattern) {
        long long op1 = cal(pattern[0] + text, pattern);
        long long op2 = cal(text + pattern[1], pattern);
    return max(op1,op2);    
    }
};