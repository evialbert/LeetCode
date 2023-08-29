class Solution {
public:
    int bestClosingTime(string c) {
        int l=c.length();
        vector<int>prefN(l,0);
        vector<int>prefY(l,0);
        vector<int>suffY(l,0);
        
        if(c[0]=='N')prefN[0]=1;
        if(c[0]=='Y')prefY[0]=1;
        for(int i=1;i<l;i++)
        {
            if(c[i]=='N'){
                prefN[i]=prefN[i-1]+1;
                prefY[i]=prefY[i-1];
            }
            else{
                prefY[i]=prefY[i-1]+1;
                prefN[i]=prefN[i-1];
            }
        }
        int temp=prefY[l-1];
        for(int i=0;i<l;i++)
        {
            suffY[i]=temp-prefY[i];
        }
        
        vector<int>penalty(l+1,0);
        
        for(int i=1;i<l;i++)
        {
            int penalti=prefN[i-1]+suffY[i];
            if(c[i]=='Y')penalti=penalti+1;
            penalty[i]=penalti;
        }
        
        penalty[0]=suffY[0];
        if(c[0]=='Y')penalty[0]=penalty[0]+1;
        penalty[l]=prefN[l-1];
        int mini=1e7;
        int ans=0;
        for(int i=l;i>=0;i--)
        {
            if(penalty[i]<=mini)
            {
                mini=penalty[i];
                ans=i;
            }
        }
        return ans;
    }
};