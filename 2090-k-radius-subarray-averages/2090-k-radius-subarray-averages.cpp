class Solution {
public:
    vector<int> getAverages(vector<int> &v, int k) {
        int n = v.size();

        vector<int> ans(n, -1);

        if((n+1)/2 <= k)
            return ans;
        
        if(k == 0)
            return v;
        
        int i = 0, j = 0;
        int windowSize = k*2 + 1;

        int idx = k;

        long long int sum = 0;
        while(j < windowSize) {
            sum += v[j++];
        }

        ans[idx++] = sum / windowSize;

        while(j < n) {
            sum -= v[i++];
            sum += v[j++];

            ans[idx++] = sum / windowSize;
        }
        
        return ans;
    }
};