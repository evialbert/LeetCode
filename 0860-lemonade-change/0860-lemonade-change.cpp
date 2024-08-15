class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f=0,t=0;
        int n=bills.size();
        for(int i=0;i<n;i++)
        {
            if(bills[i]==5)f++;
            else if(bills[i]==10)
            {
                t++;
                if(f>0)
                {
                    f--;
                    continue;
                }
                return false;
            }
            else
            {
                if(f>0&&t>0)
                {
                    f--,t--;
                    continue;
                }
                else if(f>=3)
                {
                    f-=3;
                    continue;
                }
                return false;
            }
        }
        return true;
    }
};