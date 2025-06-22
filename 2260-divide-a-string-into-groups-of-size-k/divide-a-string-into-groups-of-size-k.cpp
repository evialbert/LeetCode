class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;

        for (int i = 0; i < s.length(); i += k) {
            string str = s.substr(i, k);
            if (str.size() == k) {
                res.push_back(str);
            } else {
                if (str.size() <= k) {
                    int remaininglen = k - str.size();
                    str += string(remaininglen, fill);
                }
                res.push_back(str);
            }
        }
        return res;
    }
};