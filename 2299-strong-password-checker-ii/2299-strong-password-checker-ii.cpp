class Solution {
public:
    bool c(string s)
    {
        int count=s.size();
        int f1=0;
        int f2=0;
        int d=0;
        int sp=0;
        int a=1;
        string str="!@#$%^&*()-+";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                f1++;
            }
            if(s[i]>='a'&&s[i]<='z')
            {
                f2++;
            }
            if(s[i]>='0'&&s[i]<='9')
            {
                d++;
            }
            else if(str.find(s[i])!=string::npos)
            {
                sp++;
            }
            if(i&&s[i]==s[i-1])
            {
                a=0;
            }
        }
        return count>=8&&f1&&f2&&d&&sp&&a;
    }
    bool strongPasswordCheckerII(string p) 
    {
        return c(p);
    }
};