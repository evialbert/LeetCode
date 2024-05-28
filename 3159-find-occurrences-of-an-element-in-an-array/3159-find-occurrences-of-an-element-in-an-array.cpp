class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> res, index;
        
        // Find the indices where 'x' occurs in 'nums'
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] == x)
                index.push_back(i);
        
        // For each query, find the corresponding index (if it exists)
        for (auto num : queries) {
            if (num <= index.size())
                res.push_back(index[num - 1]);
            else
                res.push_back(-1); // Index out of bounds
        }
        return res;
    }
};