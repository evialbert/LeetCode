class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int j=0;
        int t=0;
        int res=0;
        int sum=neededTime[0]; // intial value
        int m=sum;
        for(int i=1;i<colors.length();i++)
        {
            if(colors[i]==colors[i-1])
             {
                t++;
                sum+=neededTime[i]; // update sum
                m=max(m,neededTime[i]); // update max value
            }
            else
            {
                if(t) 
                { // add sum and remove the max value ( greedy behaviour, choosing all values except max )
                    res+=sum; 
                    res-=m;
                }
                t=0;
                j=i;
                sum=neededTime[i];
                m=sum;
            }
        }
        if(t)
        {
            res+=sum;
            res-=m;
        }
        return res;
    }
};