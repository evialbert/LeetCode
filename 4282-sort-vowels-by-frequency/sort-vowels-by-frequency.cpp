class Solution {
public:
    string sortVowels(string s) {
        int a = count(s.begin(), s.end(), 'a');
        int e = count(s.begin(), s.end(), 'e');
        int in = count(s.begin(), s.end(), 'i');
        int o = count(s.begin(), s.end(), 'o');
        int u = count(s.begin(), s.end(), 'u');
        vector<int> mp(200, 0);
        int l = 1;
        for (int i = 0; i < s.length(); i++) {
            if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') && mp[s[i]] == 0) {
                mp[s[i]] = l;
                l++;
            }
        }
        vector<pair<int, char>> v = {
            {a, 'a'}, {e, 'e'}, {in, 'i'}, {o, 'o'}, {u, 'u'}};
        int h = 5;
        while (h--) {
            for (int i = 0; i < 4; i++) {
                if ((v[i].first < v[i + 1].first) || (v[i].first == v[i + 1].first &&
                    mp[v[i].second] > mp[v[i + 1].second])) {
                    swap(v[i], v[i + 1]);
                }
            }
        }
        int left = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                s[i] = v[left].second;
                v[left].first--;
                if (v[left].first == 0) {
                    left++;
                }
            }
        }
        return s;
    }
};