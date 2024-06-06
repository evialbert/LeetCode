class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
		map<int, int> m;
		for (auto &e : nums) m[e]++;
		for (auto &e : m) {
			if (e.second) {
				int freq = e.second;
				for (int i = 0; i < k; ++i) {
					if (m[e.first + i] < freq) return false;
					else m[e.first + i] -= freq;
				}
			}
		}
		return true;
    }
};