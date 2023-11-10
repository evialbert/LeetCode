class RangeFreqQuery {
public:
    map< int, vector<int> >mp;
    RangeFreqQuery(vector<int>& arr) 
    {
        int n=arr.size();
        // i base indexing
     for (int i=0; i<n; ++i)
        mp[arr[i]].push_back(i+1);
    }
    int query(int left, int right, int val) 
    {
        // i base indexing
        left++;
        right++;
        return  upper_bound(mp[val].begin(),mp[val].end(),right)-lower_bound(mp[val].begin(),mp[val].end(),left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */