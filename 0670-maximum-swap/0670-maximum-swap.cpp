class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        for(int i=0;i<s.size()-1;i++)
        {
            int maximum=s[i]-'0',index=0;
            bool flag = false;
            for(int j=s.size()-1;j>i;j--)
            {
                if(s[j]-'0'>maximum)
                {
                    index=j;
                    flag=true;
                    maximum=s[j]-'0';
                }
            }
            if(flag)
            {
                swap(s[i],s[index]);
                break;
            }
        }
        int ans = stoi(s);
        return ans;
    }
};