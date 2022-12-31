class Solution {
public:
    string discountPrices(string s, int d) {
        int i=0;
        bool num=0;
        d=100-d;//converting it to subtracter to direct multiplier
        long long t;
        string ans;
        while(i<s.size())
        {
            num=0;
            t=0;
            string tmp;
            if(s[i]=='$')//that means dollar;
            {
                num=1;
                tmp.push_back(s[i++]);
            }
                while(i<s.size()&&s[i]!=' ')
            {
                if(s[i]<'0'||s[i]>'9')//not a number
                   num=0;
                    if(num)
                        t*=10,t+=(s[i]-'0');
                tmp.push_back(s[i++]);
                   
            }
            
            if(num&&(tmp.size()>1))//checking base case "$"
            {
                
                t*=d;
               tmp="$"+to_string(t/100)+"."+(t%100<=9?"0":"")+to_string(t%100);
            }
            tmp.push_back(' ');
            ans+=tmp;
            i++;
        }
        ans.pop_back();//removing extra space
        return ans;
    }
};