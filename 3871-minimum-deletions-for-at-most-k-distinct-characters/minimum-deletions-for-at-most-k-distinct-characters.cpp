class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        int cnt=0;
        while(k<pq.size()){
            int c=pq.top().first;
            pq.pop();
            
            
            cnt+=c;

        }
        return cnt;
        
        
    }
};