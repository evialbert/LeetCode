class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        
        long long res=0;
        int l=ideas.size();
       
        unordered_set<string>mp[26];
        for(int i=0;i<l;i++)
        {
            string s=ideas[i];
            mp[s[0]-'a'].insert(s.substr(1,s.length()-1));
        }
        for(int i=0;i<26;i++)
        {
            for(int j=i+1;j<26;j++)
            {
                int b=0;
                for(auto itr : mp[i])
                {
                    if(mp[j].find(itr) == mp[j].end())b++;
                }
                int a=mp[i].size()-b;
                int c=mp[j].size()-a;
               
                res+=b*c;
            }
        }
        return res*2;
        
    }
};