class Solution {
public:
    string trimTrailingVowels(string s) {
        int len=s.length();
        if(len<1) return "";
        int right=len-1;
        while(s[right]=='a'||s[right]=='e'||s[right]=='i'||s[right]=='o'||s[right]=='u'){
           right--;
           if(right==-1) return "";
        }
        return s.substr(0,right+1);
    }
};