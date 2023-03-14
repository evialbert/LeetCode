class Solution {
    bool ispossible(string &s, string &p)
    {
        int n = p.size(), m = s.size(), i = 0, j = 0;
        while(i < n && j < m)
        {
            if(s[j] == p[i])
                i++;
            j++;
        }
        if(i == n)
            return true;
        return false;
    }
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = 0, r = removable.size()-1, ans = 0;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            string tmp = s;
            for(int i = 0; i < mid+1; i++)
            {
                tmp[removable[i]] = '*';
            }
            if(ispossible(tmp, p))
            {
                ans = mid+1;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        return ans;
    }
};