class Solution {
    bool solve(vector<int>&price,int n,int k,int mid)
    {
        int coor=price[0],cnt=1;
        for(int i=1;i<n;i++)
        {
            if(price[i]-coor>=mid)
         {
            cnt++;
            coor=price[i];
         }
         if(cnt==k)
         return true;
        }
        return false;
    }
public:
    int maximumTastiness(vector<int>& price, int k) {
         sort(price.begin(),price.end());
        int n=price.size();
        int low=1,high=price[n-1]-price[0],ans;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(solve(price,n,k,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        if(ans<0)
            return 0;
        else
        return ans;
    }
};