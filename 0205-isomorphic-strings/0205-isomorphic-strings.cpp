class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m, m2;
        for(int i=0; i<s.size(); i++){
            if(m.find(s[i])!=m.end()){
                if(m[s[i]] != t[i])
                    return false;
            }            
            else
                m[s[i]] = t[i];
        }
        
        for(int i=0; i<t.size(); i++){
            if(m2.find(t[i])!=m2.end()){
                if(m2[t[i]] != s[i])
                    return false;
            }
                
            else
                m2[t[i]] = s[i];
        }
        return true;
    }
};