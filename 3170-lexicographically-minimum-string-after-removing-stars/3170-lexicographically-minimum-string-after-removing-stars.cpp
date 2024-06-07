class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                s[-pq.top().second]='*';
                pq.pop();
            }
            else pq.push({s[i]-'a',-i});
        }
        string ans="";
        for(auto& c:s) if(c!='*') ans+=c;
        return ans;
    }
};