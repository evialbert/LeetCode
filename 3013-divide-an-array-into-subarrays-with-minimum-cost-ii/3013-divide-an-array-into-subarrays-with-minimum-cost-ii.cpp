class Solution {
public:
    long long minimumCost(std::vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long res = 0, ans;
        std::multiset<int> s1;
        std::multiset<int> s;
        std::multiset<int> s2;
        for (int i = 1; i < n && i <= dist + 1; i++) {
            s.insert(nums[i]);
        }
        int t = 1;
        for (auto& p : s) {
            if (t < k) {
                s1.insert(-p);
                res += p;
            } else {
                s2.insert(p);
            }
            t++;
        }
        ans = res;
        int r = dist + 2;
        for (int i = 2; i < n && r < n; ++i) {
            int p = nums[i - 1];
            if (s1.find(-p) != s1.end()) {
                res -= p;
                s1.erase(s1.find(-p));
                s2.insert(nums[r]);
                res += *s2.begin();
                s1.insert(-(*s2.begin()));
                s2.erase(s2.begin());
                ans = std::min(ans, res);
            } else {
                if (!s2.empty())
                    s2.erase(s2.find(p));
                if (abs(*s1.begin()) > nums[r]) {
                    int t1 = *s1.begin();
                    s1.erase(s1.find(t1));
                    s1.insert(-nums[r]);
                    s2.insert(-t1);
                    res += t1;
                    res += nums[r];
                    ans = std::min(ans, res);
                } else {
                    s2.insert(nums[r]);
                }
            }
            r++;
        }

        return ans + nums[0];
    }
};