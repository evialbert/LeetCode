class Solution {
public:
    
    int parent[100005];
    long long value[100005];

    int find(int i) {
        if(i == parent[i]) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    void unite(int i, long long& maximum, vector<int>& A) {
        int n = A.size();
        bool ok = true;
        value[i] = A[i];
        if(i + 1 < n) {
            int P = find(i + 1);
            if(value[P] != 0) {
                ok = 0;
                value[P] += value[find(i)];
                parent[find(i)] = P;
            }
        }
        if(i - 1 >= 0) {
            int P = find(i - 1);
            if(value[P] != 0) {
                ok = 0;
                value[P] += value[find(i)];
                parent[find(i)] = P;
            }
        }
        maximum = max(maximum, value[find(i)]);
    }
    vector<long long> maximumSegmentSum(vector<int>& A, vector<int>& Q) {
        int n = A.size();
        reverse(Q.begin(), Q.end());
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            value[i] = 0;
        }
        long long maximum = 0;
        vector<long long> ans(n);
        for(int i = 0; i + 1 < n; i++) {
            unite(Q[i], maximum, A);
            ans[i + 1] = maximum;  
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};