class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
       string mix=s+s;  //Adding string with it self

       for(int i=1;i<n;i++)
       {
         string str=mix.substr(i,n);
         if(str==s) 
              return true;
       }
        return false;
    }
};