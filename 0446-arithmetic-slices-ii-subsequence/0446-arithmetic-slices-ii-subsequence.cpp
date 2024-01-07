class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        int n = v.size();
        unordered_map<long, int> map[max(1, n)];
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                long diff = (long)v[i] - (long)v[j];
                map[i][diff] += 1;
                if(map[j].find(diff) != map[j].end()) {
                    map[i][diff] += map[j][diff];
                    res += map[j][diff];
                }
            }
        }
        return res;
    }
};