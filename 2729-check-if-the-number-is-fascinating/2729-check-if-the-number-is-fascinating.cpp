class Solution {
public:
    bool isFascinating(int n) {
        string str=to_string(n)+to_string(2*n)+to_string(3*n);
        int h[10]={0};
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='0')
            return false;
            h[str[i]-'0']++;
        }
        for(int i=1;i<=9;i++)
        {
            if(h[i]!=1)
            return false;
        }
        return true;
    }
};