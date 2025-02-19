class Solution {
public:
    string ans;
    
    void solve(int len, int& cnt, int n, vector<char>& v, string& s) {
        if (len == n) {
            if (--cnt == 0) {
                ans = s;
            }
            return;
        }
        for (int i = 0; i < 3; i++) {
            if (len == 0 || s.back() != v[i]) {
                s.push_back(v[i]);
                solve(len + 1, cnt, n, v, s);
                s.pop_back();
                if (cnt == 0) return;  
            }
        }
    }
    
    string getHappyString(int n, int k) {
        vector<char> v = {'a', 'b', 'c'};
        ans = "";
        string s;
        solve(0, k, n, v, s);
        return ans;
    }
};