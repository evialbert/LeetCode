class Solution {
private:
	bool check(vector<int>& bloomDay, int day, int m, int k) {
		int ct = 0, ans = 0;
		for (int i = 0; i < bloomDay.size(); ++i) {
            
			if (bloomDay[i] <= day) ct++;
			else ct = 0;
            
			if (ct == k) {
				ans++;
				ct = 0;
			}
		}
		return ans >= m;
	}
public:
	int minDays(vector<int>& bloomDay, int m, int k) {
		int lo = 1, hi = 1e9 + 1, ans = -1;

		while (lo <= hi) {
			int mid = (lo + hi) >> 1;

			if (check(bloomDay, mid, m, k)) {
				ans = mid;
				hi = mid - 1;
			}
			else lo = mid + 1;
		}
		return ans;
	}
};
