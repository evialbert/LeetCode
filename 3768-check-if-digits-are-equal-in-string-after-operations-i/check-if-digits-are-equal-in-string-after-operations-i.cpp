class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()>1){
            if(s.size()==2){
                if(s[0]==s[1]) return true;
            }
            string temp;
            for(int i=0; i<s.size()-1; i++){
                temp+=(s[i]-'0'+s[i+1]-'0')%10;
            }
            s=temp;
        }
        return false;
        
    }
};