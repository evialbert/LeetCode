class Solution {
public:
    string digitSum(string s, int k) {
        
        
        
        while(s.size()>k)
        {
            string res="";
        int n=s.size();
        int i=0;
        while(i<n)
        {
            int c=0;
            string temp="";
            int count=0;
            while(i<n && c<k)
            {
                count+=s[i]-'0';
                c++;
                i++;
            }
            string str=to_string(count);
            res+=str;
        }
            
        s=res;
        }
        return s;
    }
};