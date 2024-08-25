class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n = s.length(), m = queries.size();
        vector<int> left_index(n);
        vector<long long> subarr_count(n);
        int left = 0, right = 0, count0 = 0, count1 = 0;

        while(right < n){
            if(s[right] == '1') count1++;
            else count0++;

            while(count0 > k && count1 > k){
                if(s[left] == '1') count1--;
                else count0--;
                left++;
            }
            left_index[right] = left;
            right++;
        }

        subarr_count[0] = 1;
        for(int i = 1; i < n; i++) subarr_count[i] = subarr_count[i - 1] + (i - left_index[i] + 1);

        vector<long long> ans(m, 0);
        for(int i = 0; i < m; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            while(l <= r){
                int mid = (l + r)/2;
                if(left_index[mid] >= queries[i][0]) r = mid - 1;
                else l = mid + 1;
            }
            long long index = l;
            if(index >= queries[i][0] && index <= queries[i][1]) ans[i] += (subarr_count[queries[i][1]] - (index > 0 ? subarr_count[index - 1] : 0));
            ans[i] += (index - queries[i][0])*(index - queries[i][0] + 1)/2;
        }
        return ans;

    }
};