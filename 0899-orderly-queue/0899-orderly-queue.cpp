class Solution {
public:
    string solve(string& s) {
        int min_char = s[0];
        int max_char = s[0];
        for(int i=1; i<s.length(); i++) {
            min_char = min(min_char, (int)s[i]);
            max_char = max(max_char, (int)s[i]);
        }
        if(min_char == max_char)
            return s;
        
        vector<pair<int,int>> index;
        for(int i=0; i<s.length(); i++)
            if(s[i] == min_char)
                index.push_back({i,i});
        
        int count = index.size();
        int ind = 0;
        while(count != 1) {
            int temp_min = min_char;
            min_char = 'z'+1;
            for(int i=0; i<index.size(); i++) {
                if(index[i].first < 0) continue;
                if(s[index[i].first] == temp_min) {
                    index[i].first = (index[i].first+1)%s.length();
                    min_char = min(min_char, (int)s[index[i].first]);
                    ind = i;
                    if(index[i].first == index[i].second)
                        count = 1;
                } else {
                    index[i].first *= -1;
                    count--;
                }
            }
        }
        return  s.substr(index[ind].second, s.length()-index[ind].second) + s.substr(0, index[ind].second);
    }
    string orderlyQueue(string s, int k) {
        if(k == 1)
            return solve(s);
        int count[26] = {0};
        for(int i=0; i<s.length(); i++)
            count[s[i]-'a']++;
        for(int i=0, index=0; i<26; i++)
            while(count[i]--)
                s[index++] = i+'a';
        return s;
    }
};