class Solution {
public:
    bool isSubstringPresent(string s) {
        string p=s;
        reverse(p.begin(),p.end());
        for(int i=0; i<s.size()-1; i++){
            for(int j=0; j<s.size()-1; j++){
                if(s[i]==p[j] && s[i+1]==p[j+1]) return true;
            }
        }
        return false;
    }
};