class Solution {
public:
    int minLength(string s) {
        for(int i=0 ; i<s.size() ; i++){
            string temp="";
            temp+=s[i];
            if(i+1<s.size()){
                temp+=s[i+1];
            }
            if(temp=="AB" || temp=="CD"){
                s.erase(s.begin()+i);
                s.erase(s.begin()+i);
                i--;
                if(i!=-1){
                    i--;
                }
            }
        }
        return s.size();
    }
};