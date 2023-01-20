class Solution {
public:
    string decodeString(string s)
    {
        int i = 0;
        return decode(s, i);
    }
    
    string decode(string& s, int& idx)
    {
        string res = "";
        int iter = 1;
        while(idx < s.length())
        {
            if(s[idx] >= '0' && s[idx] <= '9')
                iter = decodeint(s, idx);
            if(s[idx] == '[')
            {
                idx++;
                string decoded = decode(s, idx);
                for(int i = 0; i < iter; i++)
                    res += decoded;
                iter = 1;
            }
            else if(s[idx] == ']') return res;
            else res += s[idx];
            idx++;
        }
        return res;
    }
    
    int decodeint(string& s, int& idx)
    {
        int res = 0;
        while(s[idx] >= '0' && s[idx] <= '9')
        {
            res *= 10;
            res += (s[idx] - '0');
            idx++;
        }
        return res;
    }
};