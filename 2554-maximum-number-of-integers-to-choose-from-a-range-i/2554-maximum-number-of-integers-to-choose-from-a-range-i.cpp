class Solution 
{
public:
    int maxCount(vector<int>& banned, int n, int maxSum) 
    {
        set<int> s;
        for(auto it: banned) s.insert(it);
        int sum=0;
        int i=1;
        int count=0;
        while(sum<maxSum && i<=n)
        {
            if(sum+i<=maxSum && s.find(i)==s.end())
            {
                sum+=i;
                count++;
            }
            else if(sum+i>maxSum) break;
            i++;
        }
        return count;
    }
};