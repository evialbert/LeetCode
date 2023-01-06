class Solution {
public:
    string greatestLetter(string s) {
        int low[26]={0},up[26]={0};
        for(auto i:s){
            if(isalpha(i)){
                if(islower(i)){
                    low[i-97]++;
                }
                else{
                    up[i-65]++;
                }
            }
        }
        for(int i=25;i>=0;i--){
            string c;
            c+=(char)i+65;
            if(up[i]>0 && low[i]>0)
                return c;
        }
        return "";
    }
};