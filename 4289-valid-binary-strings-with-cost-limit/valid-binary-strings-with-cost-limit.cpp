class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans;
        
        function<void(string, int)> rec = [&](string s, int c) ->void {
            if(s.size() == n) {
                if(c <= k) {
                    ans.push_back(s);
                }
                return;
            }

            if(s.empty()) {
                rec(s + '0', c);
                rec(s + '1', c + s.size());
            } else {
                if(s.back() == '1') {
                    rec(s + '0', c);
                } else {
                    rec(s + '0', c);
                    rec(s + '1', c + s.size());
                }
            }
        };

        rec("", 0);

        return ans;
    }
};