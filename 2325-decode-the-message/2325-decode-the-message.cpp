class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char, char> mp;
        int track = 0;
        for(int i = 0 ; i < key.length(); i++)
        {
            if(mp[key[i]] == 0 and key[i] != ' ')
            {
                mp[key[i]] = track + 'a';
                track++;
            }
        }
        string ans = "";
        for(int i = 0 ; i < message.length(); i++)
        {
            if(message[i] == ' ')
            {
                ans += ' ';
                continue;
            }
            ans += mp[message[i]];
        }
        return ans;
    }
};