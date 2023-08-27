class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        set<int>mp;
        int i=1;
        long long ans=0;
        while(mp.size()<n)
        {
            int temp=target-i;
            if(mp.find(temp)!=mp.end())
            {
                i++;
            }
             else 
             {
                mp.insert(i);
                 ans+=i;
                 i++;
                 
             }
        }
        return ans;
    }
};