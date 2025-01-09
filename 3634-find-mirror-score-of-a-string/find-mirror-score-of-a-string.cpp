class Solution {
public:
    long long calculateScore(string str) {
        long long ans=0;
        unordered_map<int,stack<int>>mp;
        for(int i=0;i<str.size();i++){
            int t=str[i]-'a';
            int s='z'-t;
            if(!mp[s].empty()){
                ans+=i;
                ans-=mp[s].top();
                mp[s].pop();
            }else{
                mp[str[i]].push(i);
            }
        }
            return ans;
        
            }
    
};