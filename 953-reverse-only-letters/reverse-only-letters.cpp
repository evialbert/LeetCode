class Solution {
public:
    bool isAlpha(char ch){
        if(ch>=65 && ch<=90 || ch>=97 && ch<=122){
            return true;
        }
        return false;
    }
    string reverseOnlyLetters(string s) {
        int l=s.length();
        int i=0,j=l;
        while(i<=j){
            if(!isAlpha(s[i])){
                i++;
            }
            else if(!isAlpha(s[j])){
                j--;
            }
            else{
                swap(s[i],s[j]);
                i++,j--;
            }
        }
        return s;
    }
};