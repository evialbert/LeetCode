class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        long long cnt[100001] = {0};
        long long pairs[100001] = {0};
        long long tuples = 0;
        for (int& x : nums) {
            if (x % 2 == 0) {
                tuples += pairs[x / 2];
            }
            if (x * 2 <= 100000)
                pairs[x] += cnt[x * 2];
            cnt[x]++;
        }
        return tuples % 1000000007;
    }
};