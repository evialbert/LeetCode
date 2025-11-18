class Solution {
public:
    string removeSubstring(string s, int k) {
        string ans = "";
        
        for (auto c : s) {
            ans += c;
            int sz = ans.size();
            
            if (sz >= 2 * k) {
                bool flag = true;
                
                // Check first k '('
                for (int i = sz - 2 * k; i < sz - k; i++) {
                    if (ans[i] != '(') {
                        flag = false;
                        break;
                    }
                }
                
                // Check last k ')'
                if (flag) {
                    for (int i = sz - k; i < sz; i++) {
                        if (ans[i] != ')') {
                            flag = false;
                            break;
                        }
                    }
                }
                
                // Remove k-balanced substring
                if (flag) {
                    ans.resize(sz - 2 * k);
                }
            }
        }
        
        return ans;
    }
};