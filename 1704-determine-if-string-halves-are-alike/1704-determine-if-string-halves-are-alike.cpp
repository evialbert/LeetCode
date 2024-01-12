class Solution {
public:
    bool halvesAreAlike(string s) {
        int start=0,end=s.length()-1,first=0,second=0;
        while(start<end){
            if(s[start]=='a' || s[start]=='e' || s[start]=='i'||s[start]=='o'||s[start]=='u' ||
               s[start]=='A' || s[start]=='E' || s[start]=='I'||s[start]=='O'||s[start]=='U')first++;
            if(s[end]=='a' || s[end]=='e' || s[end]=='i'||s[end]=='o'||s[end]=='u' ||
               s[end]=='A' || s[end]=='E' || s[end]=='I'||s[end]=='O'||s[end]=='U')second++;
            start++;end--;
        }
        return first==second;
    }
};