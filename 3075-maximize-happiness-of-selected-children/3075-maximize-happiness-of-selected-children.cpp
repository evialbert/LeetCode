class Solution
{
public:
    long long maximumHappinessSum(vector<int>& hap, int k) 
    {
        long long ans;
        ans=0;
        
        sort(hap.rbegin(),hap.rend());
        
        for(int i=0;i<k && hap[i]-i>0;i++)
        {
            ans+=hap[i]-i;
        }
        
        return ans;
    }
};