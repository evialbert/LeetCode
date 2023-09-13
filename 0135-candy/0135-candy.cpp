class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();
        vector<int> l(n,1);
        for(int i=1;i<n;i++)
        {
            if(r[i]>r[i-1])
                l[i] = l[i-1] + 1;
        }
        vector<int> ri(n,1);
        for(int i=n-2;i>=0;i--)
        {
            if(r[i]>r[i+1])
                ri[i] = ri[i+1] + 1;
        }
        int ans=0;
        for(int i =0;i<n;i++ )
            ans += max(l[i],ri[i]);
        return ans;
    }
};