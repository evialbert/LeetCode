class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> table;
	    int mx = 0;
	    for (auto&& n : nums) table[n]++, mx = max(mx, table[n]);
	    vector<vector<int>> res(mx);
	    for (auto&& r : res) {
		    vector<int> unique;
		    for (auto&& [num, amount] : table) {
			    if (amount > 0) unique.push_back(num);
			    amount--;
		    }
		    r = unique;
	    }
	    return res;
    }
};