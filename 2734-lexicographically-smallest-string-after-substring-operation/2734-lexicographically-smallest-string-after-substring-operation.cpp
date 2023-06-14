class Solution {
public:
    string smallestString(string s) {
        int n=s.size();
        int i=0;
        while(i<n && s[i]=='a') i++;
        
        if(i==n){ //if all the letters in string are 'a'
            s[i-1]='z';
            return s;
        }
        
        int j=i;
        while(j<n && s[j]!='a') j++;
        
        for(int k=i;k<j;k++){
            char c = s[k];
            char newc = s[k]-1;
            s[k]=newc;
        }
        return s;
    }
};