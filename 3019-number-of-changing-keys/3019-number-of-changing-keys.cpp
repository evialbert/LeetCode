class Solution {
public:
    int countKeyChanges(string s) {
        int c=0; 
        for(int i=0;i<s.size()-1;i++){
                if(tolower(s[i])!=tolower(s[i+1])){
                    c++;
                }
            }
        return c;
    }    
};