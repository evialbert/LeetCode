class Solution {
public:
    long long maximumSumOfHeights(vector<int>& m) {
        int n=m.size();
        long long int ans=-1;
        for(int i=0;i<m.size();i++)
        {
            long long int sum=m[i];
            int l=i-1;
            int r=i+1;
            long long int curr_a=sum;
            long long int curr_b=sum;
            for(int k=l;k>=0;k--)
            {
                if(m[k]>=curr_a)
                {
                    sum+=curr_a;
                }
                else
                {
                    sum+=m[k];
                    curr_a=m[k];
                }
            }
            for(int k=r;k<n;k++)
            {
                if(m[k]>=curr_b)
                {
                    sum+=curr_b;
                }
                else
                {
                    sum+=m[k];
                    curr_b=m[k];
                }
            }
            ans=max(ans,sum);
            
        }
        return ans;
        
    }
};