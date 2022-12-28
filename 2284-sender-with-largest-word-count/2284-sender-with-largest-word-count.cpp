class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders){
        map<string, int> mp;
        for(int i = 0; i<messages.size(); ++i){
            int words = count(begin(messages[i]), end(messages[i]), ' ')+1;
            mp[senders[i]]+=words;
        }
        string ans = "";
        int count = 0;
        for(auto it = mp.begin(); it!=mp.end(); ++it){
            if(it->second >= count){
                count = it->second;
                ans = it->first;
            }
        }
        return ans;
    }
};