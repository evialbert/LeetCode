class Solution {
public:
    string stringHash(string s, int k) {
        int n=s.length();
        int l=n/k;
        string result="";
        for(int i=0;i<l;i++)
        {
            int sum=0;
            string s1=s.substr(i*k,k);
            for(char c : s1)
            {
                sum+=(c-'a');
            }
            char hashedChar='a'+(sum%26);
            result+=hashedChar;
       }
        return result;
        
    }
};