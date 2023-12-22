class Solution {
    int mini;
public:
    void calc(vector<int>& price, vector<vector<int>>& special, vector<int>& needs,int n,int c)
    {
        if(n==0)
        {
            mini=min(c,mini);
            return;
        }
        if(c>=mini)
            return;
        for(int i=0;i<special.size();++i)
        {
            bool check=true;
            int s=0;
            for(int j=0;j<needs.size();++j)
            {
                if(needs[j]<special[i][j])
                {
                    check=false;
                }
                if(!check)
                    break;
            }
            if(check)
            {
                for(int j=0;j<needs.size();++j)
                {
                    s+=special[i][j];
                    needs[j]-=special[i][j];
                }
                calc(price,special,needs,n-s,c+special[i].back());
                for(int j=0;j<needs.size();++j)
                    needs[j]+=special[i][j];
            }
                
            }
        for(int i=0;i<price.size();++i)
            c+=(needs[i]*price[i]);
        mini=min(c,mini);
         return;
        }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n=0;
        for(int i=0;i<needs.size();++i)
            n+=needs[i];
        mini=INT_MAX;
         calc(price,special,needs,n,0);
        return mini;
    }
};