class Solution {
public:
    bool valid(string& s){
        if (s.empty()) return false;
        if (s.back() == '-' || s.front() == '-') return false;
        for (int i = 1; i + 1 < s.size(); ++i){
            if (s[i] == '-'){
                if (s[i - 1] == '-' || s[i + 1] == '-') return false;
            }
        }
        return true;
    }
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        vector<int> ans;
        unordered_map<string, int> m;
        string s;
        for (auto& str : chunks) s += str;
        string cur = "";
        for (auto& c : s){
            if (c == ' '){
                if (!cur.empty() && cur.back() == '-') cur.pop_back();
                if (valid(cur)) ++m[cur];
                cur = "";
            }
            else if (c == '-'){
                if (!cur.empty()){
                    if (!cur.empty() && cur.back() == '-'){
                        cur.pop_back();
                        if (valid(cur)) ++m[cur];
                        cur = "";
                    }
                    else cur += c;
                }
            }
            else cur += c;

            if (cur.size() >= 2 && cur.back() == '-' && cur[cur.size() - 2] == '-'){
                cur.pop_back();
                cur.pop_back();
                if (valid(cur)){
                    ++m[cur];
                }
                cur = "";
            }
        }
        if (!cur.empty() && cur.back() == '-') cur.pop_back();
        if (valid(cur)) ++m[cur];

        for (auto& q : queries){
            ans.push_back(m[q]);
        }

        return ans;
    }
};