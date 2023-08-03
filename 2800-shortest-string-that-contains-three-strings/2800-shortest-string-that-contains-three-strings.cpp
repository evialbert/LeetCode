class Solution {

public:
    string minimumString(string a, string b, string c) {
        int a_len = a.length();
        int b_len = b.length();
        int c_len = c.length();
        
        vector<vector<string>> arrangements = {
            {a, b, c},
            {a, c, b},
            {b, a, c},
            {b, c, a},
            {c, a, b},
            {c, b, a}
        };
        
        string ans = a + b + c;
        
        for (auto i : arrangements) {
            string r = "";
            
            for (auto s: i) {
                int s_len = s.length();    
                int r_len = r.length();
                bool full_matched = false;
                int min_last_ind = r.length();
                
                for (int st = 0; st < r_len; st ++) {
                    int r_ind = st, s_ind = 0;
                    while (r_ind < r_len && s_ind < s_len && s[s_ind] == r[r_ind]) 
                        r_ind ++, s_ind ++;
                    
                    if (s_ind == s_len) full_matched = true;
                    if (r_ind == r_len) min_last_ind = min (min_last_ind, st);
                }
                
                if (full_matched) continue;
                r += s.substr(r_len - min_last_ind);
            }
                        
            if (ans.length() == r.length()) ans = min (ans, r);
            else ans = (ans.length() < r.length())? ans : r;
        }
        
        return ans;
    }
};