class Solution {
public:
    long long sq(long long val) {
        return val * val;
    }
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            int val = abs(nums1[i] - nums2[i]);
            ++freq[val];
        }
        vector<pair<int, int>> diff;
        for (auto p : freq) {
            diff.push_back(p);
        }
        int totalOperations = k1 + k2;
        while (diff.size() >= 1) {
            if (diff.size() == 1) {
                long long need = (long long) diff.back().first * diff.back().second;
                if (totalOperations >= need) {
                    return 0ll;
                }
                int times = totalOperations / diff.back().second;
                int rem = totalOperations % diff.back().second;
                auto p = diff.back();
                diff.pop_back();
                diff.emplace_back(p.first - times, p.second - rem);
                diff.emplace_back(p.first - times - 1, rem);
                break;
            }
            auto last = diff.end()[-1];
            auto llast = diff.end()[-2];
            long long d = last.first - llast.first;
            long long need = d * last.second;
            if (totalOperations >= need) {
                diff.pop_back();
                diff[(int) diff.size() - 1].second += last.second;
                totalOperations -= need;
            } else {
                int times = totalOperations / diff.back().second;
                int rem = totalOperations % diff.back().second;
                auto p = diff.back();
                diff.pop_back();
                diff.emplace_back(p.first - times, p.second - rem);
                diff.emplace_back(p.first - times - 1, rem);
                break;
            }
        }
        long long sol = 0;
        for (pair<int, int> p : diff) {
            sol += (long long) p.second * sq(p.first);
        }
        return sol;
    }
};