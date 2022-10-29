class Solution {
public:
    string repeatLimitedString(string s, int limit){
        vector<int> hash(26);
        for(int i=0;i<s.length();i++) hash[s[i]-'a']++;
        priority_queue<pair<char,int>> pq; 
        for(int i=0;i<26;i++) if(hash[i]) pq.push({'a'+i,hash[i]});
        string res="";
        while(!pq.empty()){
            char c=pq.top().first; int freq=pq.top().second; pq.pop();
            int temp=min(limit,freq);
            while(temp--) res.push_back(c);
            if(pq.empty()) return res;
            freq=freq-min(limit,freq);
            if(freq){
                char smol=pq.top().first; int smolfreq=pq.top().second; pq.pop();
            res.push_back(smol); smolfreq--;
            if(smolfreq) pq.push({smol,smolfreq});
                pq.push({c,freq});
            }
            
        }
        return res;
    }
};