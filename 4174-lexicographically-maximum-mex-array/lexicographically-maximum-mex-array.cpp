class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        std::unordered_map<int, std::queue<int>> nums_idx;
        for (int i = 0; i < nums.size(); ++i) {
            nums_idx[nums[i]].push(i);
        }
        
        int k = 0;
        std::vector<int> res;
        int max_idx = 0;
        while (k < nums.size()) {
            for (int i = -1; i < 1000000; ++i) {
                if (nums_idx.find(i + 1) != nums_idx.end()) {
                    if (nums_idx[i + 1].back() < k) {
                        nums_idx.erase(i + 1);
                    } else {
                        while (!nums_idx.empty() && nums_idx[i + 1].front() < k) {
                            nums_idx[i + 1].pop();
                        }
                    }

                    if (nums_idx[i + 1].empty()) nums_idx.erase(i + 1);
                }
                
                if (nums_idx.find(i + 1) == nums_idx.end()) {
                    res.push_back(i + 1);
                    max_idx++;
                    k = max_idx;
                    break;
                } else {
                    max_idx = std::max(nums_idx[i + 1].front(), max_idx);
                    nums_idx[i + 1].pop();
                    if (nums_idx[i + 1].empty()) nums_idx.erase(i + 1);
                }
            }
        }

        return res;
        
    }
};