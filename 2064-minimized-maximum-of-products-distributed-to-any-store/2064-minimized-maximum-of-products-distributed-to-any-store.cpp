class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        sort(q.begin(), q.end());
        int m = q.size(), start = 1, end = q[m-1], ans = -1;
        if(n==m)    return end;
        while(start<=end){
            int mid = start+(end-start)/2;
            long long qCount = 0;
            for(int i=0; i<m; i++)
                qCount += (q[i]-1)/mid + 1;
            if(qCount <= n)
                ans = mid, end = mid-1;
            else
                start = mid+1;
        }
        return ans;
    }
};