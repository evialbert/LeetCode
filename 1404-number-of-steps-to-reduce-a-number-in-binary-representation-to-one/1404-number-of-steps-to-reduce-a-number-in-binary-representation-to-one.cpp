class Solution {
public:
    
    int numSteps(string s)
    {
        if (s.length() == 1)
        {
            return s[0]=='1'?0:1;
        }
        int i = s.length()-1;
        int c = 0;
        bool carry = false;
        while(i > 0)
        {
            if ((s[i] == '0') ^ (!carry))
            {
                c+=2;
                carry = true;
            }
            else
            {
                c++;
            }
            i--;
        }
        if ((s[i] == '0') ^ (carry))
        {
            c++;
        }
        return c;

    }

};