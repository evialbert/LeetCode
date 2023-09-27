class Solution {
public:
    string decodeAtIndex(string s, int k) {
        
        int n=s.length();
        long long size=0;
        
        for(char c:s)
        if(isalpha(c))
        size++;
        else
        size*=c-'0';
        
        for(int i=n-1;i>=0;i--)
        {
            k%=size;
            if(k==0 && isalpha(s[i]))
            return (string)""+s[i];
        
            if(isdigit(s[i]))
            size/=s[i]-'0';
            else
            size--;
        }
        return "";
    }
};