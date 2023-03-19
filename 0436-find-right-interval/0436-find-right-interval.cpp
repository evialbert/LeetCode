class Solution {
public:
    unordered_map<int,int> m;
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> v=intervals;
        sort(v.begin(),v.end(),cmp);// sort based on start
        vector<int> res;
        for(int i=0;i<intervals.size();i++)
            m[intervals[i][0]]=i;// map the index using start ( start is always unique )
        for(auto x:intervals)
        {
            res.push_back(find(v,x[1]));
        }
        return res;
    }
    int find(vector<vector<int>>& v,int x)//binary search 
    {
        int t=v.size();
        int l=0,r=v.size()-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            
            if(v[mid][0]>=x)
            {
                t=min(t,mid);
                r=mid-1;
            }
            else
                l=mid+1;
        }
        if(t==v.size())
            t=-1;
        else
            t=m[v[t][0]];
        return t;
    }
    static int cmp(vector<int>& a,vector<int>& b)
    {
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
            
    }
};