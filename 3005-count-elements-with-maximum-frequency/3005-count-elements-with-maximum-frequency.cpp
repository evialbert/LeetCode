class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        int max_val = INT_MIN;
        int count = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (max_val == it->second) // if current val of map == max_val
                count += max_val;       // add max val to count
            else if (it->second >= max_val) // if the current value of 
                                            // key of map is >= max_val then
            {
                count = 0;            // reset count
                max_val = it->second; // update the max value
                count = max_val;      // update the count
            }
        }
        return count;
    }
};