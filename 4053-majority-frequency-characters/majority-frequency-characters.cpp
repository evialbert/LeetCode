class Solution {
public:
    string majorityFrequencyGroup(string s) {
        int freq[26] = {};
        
        for(int i = 0; i < s.length(); ++i)
            freq[s[i] - 'a']++;

        unordered_map<int, string> mp;
        
        for(int i = 0; i < 26; ++i)
            if(freq[i])
                mp[freq[i]].push_back(i + 'a');

        int mx_freq = 0;
        string res;
        
        for(auto& [frq, str] : mp) {
            if(res.length() > str.length())
                continue;

            if(res.length() == str.length() && frq < mx_freq)
                continue;
            
            res = str;
            mx_freq = frq;
        }
        
        return res;
    }
};