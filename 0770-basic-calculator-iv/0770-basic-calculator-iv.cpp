class Number {
public:
    unordered_map <string, int> tokens;
    Number() {}
    Number(string &x, int val) {
        tokens[x] = val;
    }
    Number(int x) {
        tokens["~"] = x;
    }
    vector <string> split(const string &a) {
        stringstream ss(a);
        vector <string> ret;
        string word;
        while(getline(ss, word, '*')) 
            ret.push_back(word);
        return ret;
    }
    string normalize(string a) {
        // we want to split, sort, remove extras, and join
        vector <string> l1 = split(a); // split
        sort(l1.begin(), l1.end()); // sort
        for (int j = l1.size() - 1; j > 0 && l1[j] == "~"; j--) 
            l1.pop_back();
        string ret = "";
        for (int j = 0; j < l1.size(); j++) // join
            ret += l1[j] + "*";
        ret.pop_back();
        return ret;
    }
    void clean() {
        for (auto it = tokens.begin(); it != tokens.end(); )
            if (it->second == 0)
                tokens.erase(it++);
            else
                it++;
    }
    void add(Number &num) {
        for (auto &[key, val] : num.tokens) 
            tokens[key] += val;
        clean();
    }
    void sub(Number &num) {
        for (auto &[key, val] : num.tokens) 
            tokens[key] -= val;
        clean();
    }
    void mul(Number &num) {
        unordered_map <string, int> next;
        for (auto &[key1, val1] : tokens) 
            for (auto &[key2, val2] : num.tokens) 
                next[normalize(key1 + "*" + key2)] += val1 * val2;
        tokens = next;
        clean();
    }
    vector <string> convert() {
        vector <pair <string, int>> a(tokens.begin(), tokens.end());
        sort(a.begin(), a.end(), [](const auto &x, const auto &y) {
            int xx = x.first == "~" ? 0 : count(x.first.begin(), x.first.end(), '*'); // might need + 1 for count
            int yy = y.first == "~" ? 0 : count(y.first.begin(), y.first.end(), '*');
            return xx > yy || (xx == yy && x.first < y.first);
        });
        vector <string> ret;
        for (auto &[str, val] : a) {
            if (str == "~") 
                ret.push_back(to_string(val));
            else
                ret.push_back(to_string(val) + "*" + str);
        }
        return ret;
    }
};
class Solution {
public:
    Number getNum(string &s) {
        if (i < s.size() && s[i] == '(') {
            i++;
            Number ret = calculate(s);
            i++;
            return ret;
        }
        int sign = s[i] == '-' ? -(++i > 0) : 1;
        string cur = "";
        while (i < s.size() && (isalpha(s[i]) || isdigit(s[i]))) 
            cur += s[i++];
        if (mp.count(cur)) // amazing substitution
            return Number(mp[cur] * sign);
        if (isalpha(cur[0])) 
            return Number(cur, sign);
        return Number(stoi(cur) * sign);
    }
    Number getOperand(string &s) {
        Number ret = Number(1);
        while (i < s.size()) {
            Number num = getNum(s);
            ret.mul(num);
            if (i < s.size() && s[i] != '*')
                break ;
            i++;
        }
        return ret;
    }
    Number calculate(string &s) {
        Number ret;
        char op = '+';
        while (i < s.size() && s[i] != ')') {
            Number num = getOperand(s);
            if (op == '+')
                ret.add(num);
            else 
                ret.sub(num);
            if (i < s.size() && s[i] != ')') 
                op = s[i];
            else 
                break;
            i++;
        }
        return ret;
    }
    vector<string> basicCalculatorIV(string s, vector<string>& b, vector<int>& c) {
        for (int j = 0; j < b.size(); j++) 
            mp[b[j]] = c[j];
        remove_spaces(s);
        return calculate(s).convert();
    }
private:
    int i = 0;
    unordered_map <string, int> mp;
    void remove_spaces(string &s) {
        int ii = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == ' ') continue ;
            s[ii++] = s[j];
        }
        s.erase(ii);
    }
};