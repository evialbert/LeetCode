class Solution {
public:
    int removeAlmostEqualCharacters(string s) {
        int c=0;
        for(int i=0; i<s.size(); i++)
        {
           int a=s[i]-'a';
            int j=i+1;
            int d=0;
            while(abs((s[j]-'a')-a)<=1)
            {
                d++;
                 a=s[j]-'a';
                j++;
               
            }
            c+=d/2;
            if(d%2)
                c++;
            i=j-1;
            
        }
        return c;
       
    }
};