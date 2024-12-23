class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int c=0;
        for(char ch:s){
            if(ch=='(' && c==0){
                //skip, as this would be the first bracket so it will be considered as outermost bracket
                c++;
            }
            else if(ch=='(' && c>=1){
                ans+=ch;
                c++;
                //add ch in the string
            }
            else if(ch==')' && c>1){
                //sub ch in the string, as it's pair is alrrady added
                ans+=ch;
                c--;
            }
            else if(ch==')' && c==1){
                //skip it, outermost bracket
                c--;
            }
        }
        return ans;
    }
};