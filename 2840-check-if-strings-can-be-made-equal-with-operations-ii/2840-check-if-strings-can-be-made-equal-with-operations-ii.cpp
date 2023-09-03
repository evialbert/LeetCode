class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char,vector<int>>mp,mpp;
        for(int i=0;i<s1.size();i++)mp[s1[i]].push_back(i);
        for(int i=0;i<s2.size();i++)mpp[s2[i]].push_back(i);
            
            for(auto it:mp){
                int o=0,e=0;
                for(auto i:it.second){
                    if(i%2==0)e++;
                    else o++;
                }
                 for(auto i:mpp[it.first]){
                    if(i%2==0)e--;
                    else o--;
                }
                if(e!=0 || o!=0) return false;
            }
        return true;
     
        
      
    }
};