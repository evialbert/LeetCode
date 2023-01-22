class Solution 
{
public:
    int minNumberOfHours(int i, int e, vector<int>& ener, vector<int>& exp) 
    {
        int cnt=0, diff;
        for(int k=0; k<ener.size(); k++)
        {
            if(i<=ener[k])
            {
                diff = (ener[k]-i+1);
                i += diff;
                cnt += diff;
            }
            if(e<=exp[k])
            {
                diff = (exp[k]-e+1);
                e += diff;
                cnt += diff;
            }
            
            i -= ener[k];
            e += exp[k];
                
        }
        return cnt;
        
        
    }
};