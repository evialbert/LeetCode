class Solution {
public:
    bool check(vector<int>& pref, int cost, int mid) {
        int l = 0, r = mid;
        while (r < pref.size()) {
            int sum = pref[r] - pref[l];
            if (sum <= cost) {
                return true;
            }
            l++;
            r++;
        }
        return false;
    }

    int equalSubstring(string s, string t, int cost) {
        int n = s.size();
        vector<int> pref(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + abs(s[i - 1] - t[i - 1]);
        }

        int l = 0, h = n;
        int ans = 0;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (check(pref, cost, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return ans;
    }
};