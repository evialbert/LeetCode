class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_map<string,int> mp;
        vector<string> ans;
        int i=0;
        
        while(i+10 <= n){
            string str = s.substr(i, 10);
            
            if(mp.find(str) != mp.end() && mp[str] == 1)
                ans.push_back(str);
                
            mp[str]++;
                
            i++;
        }
        
        return ans;
    }
};